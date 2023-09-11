import java.util.Scanner;

class three{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a single digit number: ");
        int a = scan.nextInt();
        System.out.print("Word form of given number is ");
        switch(a)
        {
            case 1:
            System.out.println("One");
            break;
            case 2:
            System.out.println("Two");
            break;
            case 3:
            System.out.println("Three");
            break;
            case 4:
            System.out.println("Four");
            break;
            case 5:
            System.out.println("Five");
            break;
            case 6:
            System.out.println("Six");
            break;
            case 7:
            System.out.println("Seven");
            break;
            case 8:
            System.out.println("Eight");
            break;
            case 9:
            System.out.println("Nine");
            break;
            default:
            System.out.println("The number is not a valid single digit number");
        }
        scan.close();
    }
}