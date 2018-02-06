import java.util.Scanner;

public class Main {
    static int powerSum(int n, int startI, int remaining) {
        if(remaining == 0)
            return 1;
        if(remaining < 0)
            return 0;

        int ways = 0;
        for(int i = startI; Math.pow(i, n) <= remaining; i++)
            ways += powerSum(n, i + 1, remaining - (int) Math.pow(i, n));
        return ways;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int n = in.nextInt();
        System.out.println(powerSum(n, 1, x));
    }
}
