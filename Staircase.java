import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int size = in.nextInt(), j;

        for(int i = size - 1; i >= 0; i--) {
            for(j = 0; j < i; j++)
                System.out.print(" ");
            for(; j < size; j++)
                System.out.print("#");
            System.out.println();
        }
    }
}
