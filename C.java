class A{
void showA(){
System.out.println("A is first method");
}
}

class B extends A{
void showB(){
System.out.println("B is second method");
}
}

class C extends B{
void showC(){
System.out.println("C is third method");
}
public static void main(String args[]){
System.out.println("_____Multilevel inheritance_____");
C obj = new C();
obj.showA();
obj.showB(); 
obj.showC();  
}
}