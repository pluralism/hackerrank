import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int sum = 0;
        int inverseSum = 0;
        int[][] matrix = new int[N][N];

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                matrix[i][j] = in.nextInt();


        for(int i = 0; i < N; i++) {
            sum += matrix[i][i];
            inverseSum += matrix[i][N - i - 1];
        }
        System.out.println(Math.abs(sum - inverseSum));
    }
}
