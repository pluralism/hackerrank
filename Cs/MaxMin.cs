using System;
using System.Collections.Generic;


namespace HackerRank
{
    class Program
    {
        static void Main(String[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            int K = Int32.Parse(Console.ReadLine());
            List<int> arr = new List<int>();

            for(int i = 0; i < N; i++)
                arr.Add(Int32.Parse(Console.ReadLine()));

            arr.Sort();

            int minDiff = int.MaxValue;
            for(int i = 0; i < arr.Count - K + 1; i++)
                if (arr[i + K - 1] - arr[i] < minDiff)
                    minDiff = arr[i + K - 1] - arr[i];

            Console.WriteLine(minDiff);
        }
    }
}
