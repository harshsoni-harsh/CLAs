class Student{
    int roll_no;
    String name;
    
    public static void main(String[] args)
    {
        Student a = new Student();
        a.name = "John";
        a.roll_no = 2;
        System.out.println("name: "+a.name+"\nroll-no: "+a.roll_no);
    }
}