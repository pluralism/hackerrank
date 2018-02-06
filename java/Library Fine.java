import java.util.Calendar;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int firstDay = in.nextInt();
        int firstMonth = in.nextInt();
        int firstYear = in.nextInt();

        int secondDay = in.nextInt();
        int secondMonth = in.nextInt();
        int secondYear = in.nextInt();

        Calendar first = Calendar.getInstance();
        first.set(firstYear, firstMonth - 1, firstDay);

        Calendar second = Calendar.getInstance();
        second.set(secondYear, secondMonth - 1, secondDay);

        if(first.before(second))
            System.out.println("0");
        else if(first.get(Calendar.YEAR) != second.get(Calendar.YEAR))
            System.out.println("10000");
        else if(first.get(Calendar.MONTH) == second.get(Calendar.MONTH))
            System.out.println(15 * Math.abs(first.get(Calendar.DAY_OF_MONTH) - second.get(Calendar.DAY_OF_MONTH)));
        else if(first.get(Calendar.YEAR) == second.get(Calendar.YEAR) && first.get(Calendar.MONTH) != second.get(Calendar.MONTH))
            System.out.println(500 * Math.abs(first.get(Calendar.MONTH) - second.get(Calendar.MONTH)));
    }
}
