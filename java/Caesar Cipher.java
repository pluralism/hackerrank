import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.nextLine();
        String s = in.nextLine();
        int K = in.nextInt();

        for(int i = 0; i < s.length(); i++) {
            char tmp = s.charAt(i);
            if(Character.isLetter(tmp))
                tmp = (char) ((char) (((tmp + K) - (Character.isUpperCase(tmp) ? 'A' : 'a')) % 26) + 
                        (Character.isUpperCase(tmp) ? 'A' : 'a'));
            System.out.print(tmp);
        }
    }
}
