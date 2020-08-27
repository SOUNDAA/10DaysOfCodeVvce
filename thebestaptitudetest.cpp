using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution
{
    static void Main(String[] args)
    {
        var testCases = int.Parse(Console.ReadLine());

        for (var t = 0; t < testCases; t++)
        {
            var numStudents = int.Parse(Console.ReadLine());

            var gpas = Console.ReadLine().Split(' ').Select(double.Parse).ToList();

            var examScores = new List<double>[5];

            for(var i = 0; i < 5; i++)
            {
                examScores[i] = (Console.ReadLine().Split(' ').Select(double.Parse).ToList());
            }

            var gpaOrder = gpas.Select((gpa, i) => Tuple.Create(i, gpa)).OrderByDescending(x => x.Item2).ToList();

            var gpaOrderDict = new Dictionary<int, int>();

            for(var i = 0; i < gpaOrder.Count; i++)
            {
                gpaOrderDict[gpaOrder[i].Item1] = i;
            }

            var examScoreOrders =
                examScores.Select(
                    examList => examList.Select((score, i) => Tuple.Create(i, score)).OrderByDescending(x => x.Item2).ToList()).
                    ToArray();

            var examOrderDiffs = examScoreOrders.Select(
                examScoreList => examScoreList.Select((x, i) => Math.Abs(gpaOrderDict[x.Item1] - i)).Sum()).ToList();

            var closestMatch = examOrderDiffs.Min();

            Console.WriteLine(examOrderDiffs.IndexOf(closestMatch) + 1);
        }
    }
}