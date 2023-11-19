
using System;

public class Solution
{
    private static readonly int[] DISTANCE_RANGE = { 1, (int)Math.Pow(10, 5) };
    private static readonly int[] SPEED_RANGE = { 1, (int)Math.Pow(10, 5) };
    private static readonly int MAX_TIME_TO_REACH_THE_CITY = (int)Math.Ceiling((double)DISTANCE_RANGE[1] / SPEED_RANGE[0]);
    private readonly int[] numberOfMonstersToReachTheCityAtTimePoint = new int[MAX_TIME_TO_REACH_THE_CITY + 1];


    public int EliminateMaximum(int[] distance, int[] speed)
    {
        int totalNumberOfMonsters = distance.Length;
        InitializeArray_numberOfMonstersToReachTheCityAtTimePoint(distance, speed);
        return FindMaxNumberOfEliminatedMonsters(totalNumberOfMonsters);
    }

    private void InitializeArray_numberOfMonstersToReachTheCityAtTimePoint(int[] distance, int[] speed)
    {
        for (int i = 0; i < distance.Length; ++i)
        {
            ++numberOfMonstersToReachTheCityAtTimePoint[(int)Math.Ceiling((double)distance[i] / speed[i])];
        }
    }

    private int FindMaxNumberOfEliminatedMonsters(int totalNumberOfMonsters)
    {
        int eliminatedMonsters = 1;

        for (int time = 0; time < numberOfMonstersToReachTheCityAtTimePoint.Length; ++time)
        {

            numberOfMonstersToReachTheCityAtTimePoint[time] += time > 0 ? numberOfMonstersToReachTheCityAtTimePoint[time - 1] : 0;

            //can eliminate monsters only at a distance
            if (eliminatedMonsters <= numberOfMonstersToReachTheCityAtTimePoint[time])
            {
                --eliminatedMonsters;
                break;
            }
            if (eliminatedMonsters == totalNumberOfMonsters)
            {
                break;
            }
            ++eliminatedMonsters;
        }
        return eliminatedMonsters;
    }
}
