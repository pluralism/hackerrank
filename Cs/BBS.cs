using System;
using System.Text.RegularExpressions;

namespace HackerRank
{
    class Program
    {
        static void Main(String[] args)
        {
            Console.ReadLine();
            string s = Console.ReadLine();
            Console.WriteLine(Regex.Matches(s, "010").Count);
        }
    }
}
