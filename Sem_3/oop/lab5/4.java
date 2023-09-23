import java.util.Scanner;
class Solution
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        scan.close();
        Stack arr = new Stack(s.length());
        boolean correct = true;
        for(int i=0; i<s.length(); i++)
        {
            if(s.charAt(i) == '}')
            {
                if(arr.peek() != '{')
                {
                    correct = false;
                }
                else
                {
                    arr.pop();
                }
            }
            else if(s.charAt(i) == ')')
            {
                if(arr.peek() != '(')
                {
                    correct = false;
                }
                else
                {
                    arr.pop();
                }
            }
            else if(s.charAt(i) == ']' )
            {
                if(arr.peek() != '[')
                {
                    correct = false;
                }
                else
                {
                    arr.pop();
                }
            }
            else
            {
                arr.push(s.charAt(i));
            }
        }
        System.out.println(correct);
    }
}
class Stack
{
    char[] arr;
    int top = -1;
    Stack(int size)
    {
        arr = new char[size];
    }
    void push(char n)
    {
        top++;
        arr[top] = n;
    }
    void pop()
    {
        if(top>-1)
        {
            top--;
        }
    }
    char peek()
    {
        if(top>-1)
        {
            return arr[top];
        }
        return 0;
    }
}