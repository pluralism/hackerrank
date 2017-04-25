using System;
using System.Collections.Generic;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        static void Main(String[] args)
        {
            Console.ReadLine();
            List<int> candles = Console.ReadLine().Split(' ').Select(c => Int32.Parse(c)).OrderBy(c => c).ToList();
            Console.WriteLine(candles.Where(c => c == candles.Last()).Count());
        }
    }
}
