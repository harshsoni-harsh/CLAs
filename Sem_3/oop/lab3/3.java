import java.util.Scanner;

class Area
{
    public Area(int a1,int a2)
    {
        System.out.println("Area is "+returnArea(a1,a2));
    }
    int returnArea(int a1, int a2)
    {
        return  a1*a2;
    }
    public static void main(String[] args)
    {
        int a,b;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a and b: ");
        a=scan.nextInt();
        b=scan.nextInt();
        Area a1 = new Area(a,b);
        scan.close();
    }
}