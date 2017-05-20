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
                if(num[i] == num[num.Length - i - 1] && num[i] != '9')
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
                    if(repNeed > 0) repNeed--;
                    int toChange = 0;
                    if (num[i] != '9')
                        toChange++;
                    if (num[num.Length - i - 1] != '9')
                        toChange++;


                    if(toChange == 1)
                    {
                        int newK = currentK - toChange;
                        if(newK >= 0 && newK >= repNeed)
                        {
                            if (num[i] < num[num.Length - i - 1])
                            {
                                num[i] = num[num.Length - i - 1];
                                currentK--;
                            }
                            else if (num[i] > num[num.Length - i - 1])
                            {
                                num[num.Length - i - 1] = num[i];
                                currentK--;
                            }
                        }
                    }


                    if(toChange == 2)
                    {
                        int newK = currentK - toChange;
                        if(newK >= 0 && newK >= repNeed)
                        {
                            num[i] = '9';
                            num[num.Length - i - 1] = '9';
                            currentK -= 2;
                        } else if(currentK - 1 >= 0 && currentK - 1 >= repNeed)
                        {
                            if (num[i] < num[num.Length - i - 1])
                            {
                                num[i] = num[num.Length - i - 1];
                                currentK--;
                            }
                            else if (num[i] > num[num.Length - i - 1])
                            {
                                num[num.Length - i - 1] = num[i];
                                currentK--;
                            }
                        }
                    }
                }
                if (currentK < 0)
                    return "-1";
            }

            if(num.Length % 2 == 1 && currentK > 0)
                num[num.Length >> 1] = '9';

            return new string(num);
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
