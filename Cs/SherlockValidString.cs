using System;
using System.Collections.Generic;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        static bool IsValid(string s)
        {
            Dictionary<char, int> freqs = new Dictionary<char, int>();
            Dictionary<int, int> aa = new Dictionary<int, int>();
            foreach(char c in s)
            {
                if (!freqs.ContainsKey(c)) freqs[c] = 0;
                freqs[c]++;
            }
            foreach(int a in freqs.Values)
            {
                if (!aa.ContainsKey(a)) aa[a] = 0;
                aa[a]++;
            }
            List<int> vals = freqs.Values.ToList();
            int min = vals.Min(), sum = 0;
            foreach(int i in vals) sum += Math.Abs(min - i);

            List<int> v = vals.Distinct().ToList();
            return sum <= 1 || (v.Count() == 2 && aa[v.Min()] == 1);
        }
    }
}
