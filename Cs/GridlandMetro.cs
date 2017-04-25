using System;
using System.Collections.Generic;
using System.Linq;


namespace HackerRank
{
    class Program
    {
        static long MergeIntervals(List<Tuple<long, long>> intervals)
        {
            long res = 0;
            if (intervals.Count == 1)
                return intervals[0].Item2 - intervals[0].Item1 + 1;

            Stack<Tuple<long, long>> s = new Stack<Tuple<long, long>>();
            intervals = intervals.OrderBy(n => n.Item1).ToList();
            s.Push(intervals[0]);

            for(int i = 1; i < intervals.Count(); i++)
            {
                Tuple<long, long> tmp = s.Peek();

                if (tmp.Item2 < intervals[i].Item1)
                    s.Push(intervals[i]);
                else if(tmp.Item2 < intervals[i].Item2)
                {
                    tmp = Tuple.Create(tmp.Item1, intervals[i].Item2);
                    s.Pop();
                    s.Push(tmp);
                }
            }

        
            while(s.Count != 0)
            {
                Tuple<long, long> t = s.Peek();
                res += t.Item2 - t.Item1 + 1;
                s.Pop();
            }

            return res;
        }


        static void Main(String[] args)
        {
            List<long> info = Console.ReadLine().Split(' ').Select(n => Int64.Parse(n)).ToList();
            long totalCells = info[0] * info[1];
            Dictionary<long, List<Tuple<long, long>>> intervals = new Dictionary<long, List<Tuple<long, long>>>();

            for (long i = 0; i < info[2]; i++)
            {
                List<long> tmp = Console.ReadLine().Split(' ').Select(n => Int64.Parse(n)).ToList();
                if (!intervals.ContainsKey(tmp[0]))
                    intervals[tmp[0]] = new List<Tuple<long, long>>();
                intervals[tmp[0]].Add(Tuple.Create(tmp[1], tmp[2]));
            }

            long occupied = 0;
            foreach(long key in intervals.Keys)
                occupied += MergeIntervals(intervals[key]);
            Console.WriteLine(totalCells - occupied);
        }
    }
}
