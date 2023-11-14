import java.util.*;
abstract class string_matcher {
    abstract public boolean match(String a);
}
class word_matcher extends string_matcher {
    public boolean match(String a) {
        for (char i : a.toCharArray()) {
            if(!Character.isLetter(i)) {
                return false;
            }
        }
        return !a.isBlank();
    }
}
class number_matcher extends string_matcher {
    public boolean match(String a) {
        try {
            int x = Integer.parseInt(a);
            return true;
        }
        catch (NumberFormatException nfe) {
            return false;
        }
    }
}
class blank_string_matcher extends string_matcher {
    public boolean match(String a) {
        return a.isBlank();
    }
}
class Solution {
    public static void main(String[] args) {
        word_matcher w = new word_matcher();
        Scanner s = new Scanner(System.in);
        String a = s.nextLine();
        System.out.println("Is it a word: "+w.match(a));
        number_matcher n = new number_matcher();
        System.out.println("Is it a number: "+n.match(a));
        blank_string_matcher b = new blank_string_matcher();
        System.out.println("Is it a blank string: "+b.match(a));
    }
}