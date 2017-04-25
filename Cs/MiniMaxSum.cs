using System;
using System.Collections.Generic;
using System.Linq;


namespace HackerRank
{
    class MiniMaxSum
    {
        static void Main(string[] args)
        {
            string line = Console.ReadLine();
            List<long> nums = line.Split(' ').Select(n => Int64.Parse(n)).OrderBy(n => n).ToList();
            Console.WriteLine($"{nums.Take(4).Sum()} {nums.Skip(1).Take(4).Sum()}");
        }
    }
}
