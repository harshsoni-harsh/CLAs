class A {
    static int x=0;
}
class B {
    static int y=3;
}
class C extends A, B{
    static int c=9;
}
class Solution {
    public static void main(String[] args) {
        System.out.println(C.c);
    }
}