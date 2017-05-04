using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Program
    {
        static HashSet<int> CalculateWeights(string s)
        {
            HashSet<int> weights = new HashSet<int>();
            char lastChar = s[0];
            int count = 1;

            weights.Add(lastChar - 97 + 1);

            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == lastChar)
                    count++;
                else
                {
                    count = 1;
                    lastChar = s[i];
                }
                weights.Add(count * (lastChar - 97 + 1));
            }

            return weights;
        }

        static void Main(String[] args)
        {
            string s = Console.ReadLine();
            HashSet<int> weights = CalculateWeights(s);
            int n = Int32.Parse(Console.ReadLine());
            for(int i = 0; i < n; i++)
            {
                int tmp = Int32.Parse(Console.ReadLine());
                if (weights.Contains(tmp))
                    Console.WriteLine("Yes");
                else
                    Console.WriteLine("No");
            }
        }
    }
}
