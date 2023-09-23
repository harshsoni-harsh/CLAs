import java.util.HashMap;
import java.util.Scanner;

class Solution {
    static String findShortestSubstring(String s, String b) {
        int minLen = Integer.MAX_VALUE;
        String shortestSubstring = null;
        HashMap<Character, Integer> charCount = new HashMap<>();
        
        for (char c : b.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        int left = 0, count = b.length();
        
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            if (charCount.containsKey(rightChar)) {
                charCount.put(rightChar, charCount.get(rightChar) - 1);
                if (charCount.get(rightChar) >= 0) {
                    count--;
                }
            }
            
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    shortestSubstring = s.substring(left, right + 1);
                }
                
                char leftChar = s.charAt(left);
                if (charCount.containsKey(leftChar)) {
                    charCount.put(leftChar, charCount.get(leftChar) + 1);
                    if (charCount.get(leftChar) > 0) {
                        count++;
                    }
                }
                left++;
            }
        }
        
        return shortestSubstring;
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String b = scan.nextLine();
        scan.close();
        
        String shortestSubstring = findShortestSubstring(s, b);
        
        if (shortestSubstring == null) {
            System.out.println("Substring not found");
        } else {
            System.out.println(shortestSubstring);
        }
    }
}
