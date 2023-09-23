import java.util.Scanner;
class Solution
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String b = scan.nextLine();
        scan.close();
        s = s.toLowerCase();
        b = b.toLowerCase();
        int[] counts = new int[150];
        int[] counts2 = new int[150];
        for (int i=0; i<s.length(); i++)
        {
            counts[(s.charAt(i))]++;
        }
        for (int i=0; i<b.length(); i++)
        {
            counts2[b.charAt(i)]++;
        }
        boolean same = true;
        if(s.length() != b.length())
        {
            same = false;
        }
        else
        {
            for (int i=0; i<150; i++)
            {
                if(counts[i] != counts2[i])
                {
                    same = false;
                    break;
                }
            }
        }
        System.out.println(same);
    }
}