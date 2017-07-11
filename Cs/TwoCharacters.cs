using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static int GetLen(string s, char a, char b)
        {
            char current = a;
            for(int i = 1; i < s.Length; i++)
            {
                if (s[i] == current)
                    return -1;
                current = s[i];
            }
            return s.Length;
        }

        static void Main(string[] args)
        {
            int max = 0;
            Console.ReadLine();
            string s = Console.ReadLine();
            char[] chars = s.ToCharArray().Distinct().ToArray();
            for(int i = 0; i < chars.Length - 1; i++)
            {
                for(int j = i + 1; j < chars.Length; j++)
                {
                    string tmp = new string(s.Where(c => c == chars[i] || c == chars[j]).ToArray());
                    max = Math.Max(GetLen(tmp, tmp[0], tmp[1]), max);
                }
            }
            Console.WriteLine(max);
        }
    }
}
