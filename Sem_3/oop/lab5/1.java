import java.util.Scanner;
class Solution
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int max=0;
        char maxc='a';
        int count;
        for (int i=0; i<s.length(); i++)
        {
            count=0;
            for (int j=0; j<s.length(); j++)
            {
                if(s.charAt(i) == s.charAt(j))
                {
                    count++;
                }
            }
            if(max < count)
            {
                max = count;
                maxc = s.charAt(i);
            }
        }
        System.out.println(maxc);
        scan.close();
    }
}