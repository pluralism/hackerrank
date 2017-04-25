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
