import java.util.Scanner;

class Five{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int[][] arr = new int[6][6];
        for (int i = 0; i < 6; i++)
        {
            for (int j =0; j<6; j++)
            {
                arr[i][j] = scan.nextInt();
            }
        }
        scan.close();
        System.out.println("Computing...");
        int max = -1000;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int sum = 
                arr[0+i][0+j]+arr[0+i][1+j]+arr[0+i][2+j]+
                arr[1+i][1+j]+
                arr[2+i][0+j]+arr[2+i][1+j]+arr[2+i][2+j];
                max = (max<sum) ? sum : max;
            }
        }
        System.out.println(max);
    }
}
