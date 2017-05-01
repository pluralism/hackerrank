using System;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        static void SplitNumber(string s)
        {
            int currentIndex = 0, len = 1, curSize = 1;
            long num = 0, nextNum = 0, firstPart = 0;
            string numS = s.Substring(currentIndex, len);
            firstPart = long.Parse(numS);
            while (true)
            {
                num = long.Parse(numS);
                nextNum = num + 1;
                len = nextNum.ToString().Length;
                currentIndex += numS.Length;
                if (currentIndex + len > s.Length)
                {
                    Console.WriteLine("NO");
                    break;
                }

                numS = s.Substring(currentIndex, len);
                if (long.Parse(numS) != nextNum)
                {
                    currentIndex = 0;
                    curSize++;
                    numS = s.Substring(currentIndex, curSize);
                    firstPart = long.Parse(numS);
                } else
                {
                    if (currentIndex + len == s.Length)
                    {
                        Console.WriteLine("YES {0}", firstPart);
                        break;
                    }
                }
            }
        }


        static void Main(String[] args)
        {
            int q = Convert.ToInt32(Console.ReadLine());
            for (int a0 = 0; a0 < q; a0++)
            {
                string s = Console.ReadLine();
                SplitNumber(s);
            }
        }
    }
}
