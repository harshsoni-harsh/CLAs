import java.util.Scanner;

class Four{
    public static void main(String[] args)
    {
        System.out.print("Enter a number: ");
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for (int i=1; i<11; i++)
        {
            System.out.println(n+" x "+i+" = "+n*i);
        }
        scan.close();
    }
}