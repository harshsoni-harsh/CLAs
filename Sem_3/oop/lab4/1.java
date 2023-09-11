class Solution
{
    public static void main(String[] args)
    {
        Student[] a1 = new Student[10];
        for(int i=0; i<10; i++)
        {
            a1[i] = new Student();
            a1[i].setInfo("something"+i, 13+i);
            if(i%3==0)
            {
                a1[i].setInfo("something"+i, 13+i, "House no.: "+i+", Area: india");
            }
            System.out.println("Name: "+a1[i].name+", Age: "+a1[i].age+", Address: "+a1[i].address);
        }
    }
}
class Student
{
    public String name = "unknown";
    public int age = 0;
    public String address = "not available";
    public void setInfo(String name_var, int age_var)
    {
        name = name_var;
        age = age_var;
    }
    public void setInfo(String name_var, int age_var, String address_var)
    {
        name = name_var;
        age = age_var;
        address = address_var;
    }
}