using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Program
    {
        static void IceCreamParlor(int totalDollars, string s)
        {
            Dictionary<int, List<int>> nums = new Dictionary<int, List<int>>();
            string[] arr = s.Split(' ');
            for (int i = 0; i < arr.Length; i++)
            {
                int numInt = Int32.Parse(arr[i]);
                if (!nums.ContainsKey(numInt))
                    nums[numInt] = new List<int>();

                nums[numInt].Add(i + 1);
            }

            int firstPos = -1, lastPos = -1;
            foreach (int num in nums.Keys)
            {
                if (nums.ContainsKey(totalDollars - num))
                {
                    if (totalDollars - num == num && nums[num].Count > 1)
                    {
                        firstPos = nums[num][0];
                        lastPos = nums[num][1];
                        break;
                    }
                    else if(totalDollars - num != num)
                    {
                        firstPos = nums[num][0];
                        lastPos = nums[totalDollars - num][0];
                        break;
                    }
                }
            }

            Console.WriteLine("{0} {1}", Math.Min(firstPos, lastPos), Math.Max(firstPos, lastPos));
        }

        static void Main(String[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int totalDollars = Int32.Parse(Console.ReadLine());
                Console.ReadLine();
                string s = Console.ReadLine();
                IceCreamParlor(totalDollars, s);
            }
        }
    }
}
