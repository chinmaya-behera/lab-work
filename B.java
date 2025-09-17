class A{
void show(){
System.out.println("A is first method");
}
}
class B extends A{
void showB(){
System.out.println("B is second method");
}
public static void main(String args[]){
System.out.println("_____Single inheritance_____");
B obj = new B();
obj.show();
obj.showB();
}
}