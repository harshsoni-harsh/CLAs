import java.util.Scanner;

class Employee
{
    int salary, no_of_hours;
    void getInfo(int sal, int hr)
    {
        salary = sal;
        no_of_hours = hr;
    }
    void AddSal()
    {
        if(salary<500)
        {
            salary+=10;
        }
    }
    void AddWork()
    {
        if(no_of_hours>6)
        {
            salary+=5;
        }
    }
    public static void main(String[] args)
    {
        int a,b;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter salary: ");
        a=scan.nextInt();
        System.out.println("Enter number of hours: ");
        b=scan.nextInt();

        Employee emp = new Employee();
        emp.getInfo(a, b);
        System.out.println("Current salary is "+emp.salary);
        emp.AddSal();
        emp.AddWork();
        System.out.println("Final salary is "+emp.salary);
        scan.close();
    }
}