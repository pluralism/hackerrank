using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            Dictionary<int, List<string>> mappings = new Dictionary<int, List<string>>();

            for (int i = 0; i < N; i++)
            {
                string[] vals = Console.ReadLine().Split(' ');
                int num = Int32.Parse(vals[0]);
                bool firstHalf = i < N / 2;
                if (!mappings.ContainsKey(num))
                    mappings[num] = new List<string>();

                mappings[num].Add(firstHalf ? "-" : vals[1]);
            }

            List<int> sortedKeys = mappings.Keys.ToList();
            sortedKeys.Sort();

            foreach(int n in sortedKeys)
                foreach (string elem in mappings[n])
                    Console.Write(elem + " ");
        }
    }
}
