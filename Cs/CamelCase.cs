using System;
using System.Linq;

namespace HackerRank
{
    class Program
    {
        static void Main(String[] args)
        {
            string s = Console.ReadLine();
            int count = s.Count(c => char.IsUpper(c));
            Console.WriteLine(count + 1);
        }
    }
}
