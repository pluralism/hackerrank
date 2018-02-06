import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<Integer, Integer> valsHash = new HashMap<>();
        HashSet<Integer> covered = new HashSet<>();
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int total = 0, index = k - 1;

        while(index < n) {
            if(arr[index] == 1) {
                // Is this the last point?
                if(index + 2 * k > n) {
                    // Check if it won't hit the last index...
                    if(index + k < n) {
                        index--;
                        continue;
                    }
                }

                if(valsHash.containsKey(index) && valsHash.get(index) > 1) {
                    int tmp = index - 1;
                    while(tmp > -1) {
                        if(arr[tmp] == 1 && (!valsHash.containsKey(tmp) || valsHash.get(tmp) < 2)) {
                            index = tmp;
                            total--;
                            break;
                        }
                        tmp--;
                    }


                    if(tmp == -1) {
                        tmp = index;
                        while(tmp < n) {
                            if(arr[tmp] == 1 && (!valsHash.containsKey(tmp) || valsHash.get(tmp) < 2)) {
                                index = tmp;
                                break;
                            }
                            tmp++;
                        }
                    }
                }
                
                if(!valsHash.containsKey(index))
                    valsHash.put(index, 0);
                valsHash.put(index, valsHash.get(index) + 1);


                for(int i = index - k; i <= index + k; i++)
                    if(i >= 0 && i < n)
                        covered.add(i);
                index += 2 * k - 1;
                total++;
            } else {
                index--;
                if(index < 0) {
                    total = -1;
                    break;
                }
            }
        }

        if(n - covered.size() > k)
            total = -1;
        System.out.println(total);
    }
}
