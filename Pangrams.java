import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    static void pangram(String s) {
        s = s.toLowerCase();
        Map<Character, Integer> chars = new HashMap<Character, Integer>();
        int uniqueChars = 0;

        for(int i = 0; i < s.length(); i++) {
            if(Character.isAlphabetic(s.charAt(i)) && !chars.containsKey(s.charAt(i))) {
                uniqueChars++;
                chars.put(s.charAt(i), 1);
            }

            if(uniqueChars == 26)
                break;
        }

        if(uniqueChars == 26)
            System.out.println("pangram");
        else
            System.out.println("not pangram");
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        pangram(s);
    }
}
