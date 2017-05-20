using System;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        public static string Calculate(char[] num, int maxK)
        {
            int repNeed = 0;

            for(int i = 0; i < num.Length / 2; i++)
                if (num[i] != num[num.Length - i - 1])
                    repNeed++;


            int currentK = maxK;

            for(int i = 0; i < num.Length / 2; i++)
            {
                if(num[i] == num[num.Length - i - 1])
                {
                    int newK = currentK - 2;
                    if(newK >= repNeed)
                    {
                        num[i] = '9';
                        num[num.Length - i - 1] = '9';
                        currentK -= 2;
                    }
                } else
                {

                }
            }

            Console.WriteLine(new string(num));
            return "";
        }

        static void Main(String[] args)
        {
            string[] vals = Console.ReadLine().Split(' ');
            int K = Int32.Parse(vals[1]);
            char[] num = Console.ReadLine().ToCharArray();
            Console.WriteLine(Calculate(num, K));

            Console.ReadLine();
        }
    }
}
