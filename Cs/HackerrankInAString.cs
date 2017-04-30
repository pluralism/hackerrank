using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;


namespace HackerRank
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int n = Int32.Parse(Console.ReadLine());
            for(int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                Regex regex = new Regex(@"(h.*a.*c.*k.*e.*r.*r.*a.*n.*k)");
                Match match = regex.Match(s);
                if(match.Success)
                    Console.WriteLine("YES");
                else
                    Console.WriteLine("NO");
            }
        }
    }
}
