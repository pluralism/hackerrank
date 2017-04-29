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
            int errors = 0;
            string secretWord = "SOS";
            string s = Console.ReadLine();
            List<string> stringList = Enumerable.Range(0, s.Length / 3).Select(x => s.Substring(x * 3, 3)).ToList();
            foreach(string tmp in stringList)
                for(int i = 0; i < tmp.Length; i++)
                    if(tmp[i] != secretWord[i])
                        errors++;
            Console.WriteLine(errors);
        }
    }
}
