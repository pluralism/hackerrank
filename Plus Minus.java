import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int size = in.nextInt(), tmp;
        int negative = 0, positive = 0, zero = 0;

        for(int i = 0; i < size; i++) {
            tmp = in.nextInt();
            if (tmp < 0)
                negative++;
            else if(tmp > 0)
                positive++;
            else
                zero++;
        }
        System.out.printf("%.3f\n", (float) positive / size);
        System.out.printf("%.3f\n", (float) negative / size);
        System.out.printf("%.3f\n", (float) zero / size);
    }
}
