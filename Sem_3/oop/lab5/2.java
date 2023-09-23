import java.util.Scanner;
class Solution
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String b = scan.nextLine();
        s = s.toLowerCase();
        b = b.toLowerCase();
        String out = "";
        for (int i=0; i<s.length(); i++)
        {
            boolean in = true;
            for (int j=0; j<b.length(); j++)
            {
                if(s.charAt(i) == b.charAt(j))
                {
                    in = false;
                }
            }
            if(in)
            {
                out += s.charAt(i);
            }
        }
        System.out.println(out);
        scan.close();
    }
}