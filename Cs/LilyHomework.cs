using System;
using System.Collections.Generic;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        static int CheckArray(ref List<int> arr, ref Dictionary<int, int> dict, List<int> sorted)
        {
            int count = 0;
            for (int i = 0; i < arr.Count(); i++)
            {
                if (arr[i] != sorted[i])
                {
                    int sortedI = sorted[i];
                    int arrI = arr[i];
                    int indexSorted = dict[sortedI];
                    dict[sorted[i]] = i;
                    dict[arr[i]] = indexSorted;

                    arr[i] = arr[indexSorted];
                    arr[indexSorted] = arrI;

                    count++;
                }
            }
            return count;
        }

        static void Main(String[] args)
        {
            int count = 0, count1 = 0;
            Console.ReadLine();
            List<int> original = Console.ReadLine().Split(' ').Select(n => Int32.Parse(n)).ToList();
            List<int> arr = new List<int>(original);
            List<int> sorted = arr.OrderBy(n => n).ToList();
            Dictionary<int, int> dict = arr.Select((n, i) => new { n, i }).ToDictionary(x => x.n, x => x.i);

            count = CheckArray(ref arr, ref dict, sorted);

            arr = new List<int>(original);
            sorted = arr.OrderBy(n => -n).ToList();
            dict = arr.Select((n, i) => new { n, i }).ToDictionary(x => x.n, x => x.i);

            count1 = CheckArray(ref arr, ref dict, sorted);

            Console.WriteLine(Math.Min(count, count1));
        }
    }
}
