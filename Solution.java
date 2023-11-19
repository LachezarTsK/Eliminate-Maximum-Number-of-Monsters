
public class Solution {

    private static final int[] DISTANCE_RANGE = {1, (int) Math.pow(10, 5)};
    private static final int[] SPEED_RANGE = {1, (int) Math.pow(10, 5)};
    private static final int MAX_TIME_TO_REACH_THE_CITY = (int) Math.ceil((double) DISTANCE_RANGE[1] / SPEED_RANGE[0]);
    private final int[] numberOfMonstersToReachTheCityAtTimePoint = new int[MAX_TIME_TO_REACH_THE_CITY + 1];

    public int eliminateMaximum(int[] distance, int[] speed) {
        int totalNumberOfMonsters = distance.length;
        initializeArray_numberOfMonstersToReachTheCityAtTimePoint(distance, speed);
        return findMaxNumberOfEliminatedMonsters(totalNumberOfMonsters);
    }

    private void initializeArray_numberOfMonstersToReachTheCityAtTimePoint(int[] distance, int[] speed) {
        for (int i = 0; i < distance.length; ++i) {
            ++numberOfMonstersToReachTheCityAtTimePoint[(int) Math.ceil((double) distance[i] / speed[i])];
        }
    }

    private int findMaxNumberOfEliminatedMonsters(int totalNumberOfMonsters) {
        int eliminatedMonsters = 1;

        for (int time = 0; time < numberOfMonstersToReachTheCityAtTimePoint.length; ++time) {

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
}
