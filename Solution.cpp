
#include <span>
#include <array>
#include <vector>
using namespace std;

/*
In this particular case 'customMath::ceil(...)' is not necessary since
'MAX_TIME_TO_REACH_THE_CITY = 100000/1' but if there is a change in range values
it comes in handy because 'std::ceil(...)' is not a consteval and we need 
 compile time constant for the number of elements in class template 'array'.
 */
namespace customMath {

    consteval double ceil(double num) {
        if (num == 0) {
            return 0;
        }
        if (num <= 1) {
            return 1;
        }
        return (num / static_cast<int> (num) == 1) ? num : (static_cast<int> (num) + 1);
    };
}

class Solution {
    
    static constexpr array<int, 2> DISTANCE_RANGE{1, 100000};
    static constexpr array<int, 2> SPEED_RANGE{1, 100000};
    static constexpr int MAX_TIME_TO_REACH_THE_CITY = customMath::ceil(static_cast<double> (DISTANCE_RANGE[1]) / SPEED_RANGE[0]);
    array<int, MAX_TIME_TO_REACH_THE_CITY + 1> numberOfMonstersToReachTheCityAtTimePoint{};

public:
    int eliminateMaximum(const vector<int>& distance, const vector<int>& speed) {
        int totalNumberOfMonsters = distance.size();
        initializeArray_numberOfMonstersToReachTheCityAtTimePoint(distance, speed);
        return findMaxNumberOfEliminatedMonsters(totalNumberOfMonsters);
    }
    
private:
    void initializeArray_numberOfMonstersToReachTheCityAtTimePoint(span<const int> distance, span<const int> speed) {
        for (int i = 0; i < distance.size(); ++i) {
            ++numberOfMonstersToReachTheCityAtTimePoint[ceil(static_cast<double> (distance[i]) / speed[i])];
        }
    }

    int findMaxNumberOfEliminatedMonsters(int totalNumberOfMonsters) {
        int eliminatedMonsters = 1;

        for (int time = 0; time < numberOfMonstersToReachTheCityAtTimePoint.size(); ++time) {

            numberOfMonstersToReachTheCityAtTimePoint[time] += time > 0 ? numberOfMonstersToReachTheCityAtTimePoint[time - 1] : 0;

            //can eliminate monsters only at a distance
            if (eliminatedMonsters <= numberOfMonstersToReachTheCityAtTimePoint[time]) {
                --eliminatedMonsters;
                break;
            }
            if (eliminatedMonsters == totalNumberOfMonsters) {
                break;
            }
            ++eliminatedMonsters;
        }
        return eliminatedMonsters;
    }
};
