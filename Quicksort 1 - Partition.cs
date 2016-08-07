using System;
using System.Collections.Generic;
using System.IO;

class Program {
    static void partition(int[] arr)
    {
        int p = arr[0];
        List<int> left, equal, right;
        left = new List<int>();
        equal = new List<int>();
        right = new List<int>();

        foreach(int num in arr)
        {
            if (num == p)
                equal.Add(num);
            else if (num >= p)
                right.Add(num);
            else
                left.Add(num);
        }

        Console.Write(String.Join(" ", left));
        Console.Write(" " + String.Join(" ", equal));
        Console.Write(" " + String.Join(" ", right));
    }


    static void Main(String[] args)
    {
        int arr_size;
        arr_size = Convert.ToInt32(Console.ReadLine());
        int[] arr = new int[arr_size];
        String elements = Console.ReadLine();
        String[] split_elements = elements.Split(' ');
        for(int i = 0; i < arr_size; i++)
            arr[i] = Convert.ToInt32(split_elements[i]);

        partition(arr);
    }
}
