class A{
void show(){
System.out.println("A is a method");
}
}

class B extends A{
void show(){
System.out.println("B is a method");
}
}

class D{
public static void main(String args[]){
System.out.println("Method Overriding");
B obj =new B();
obj.show();
A obj1=new A();
obj1.show();
}
}