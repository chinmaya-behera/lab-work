class A{
void showA(){
System.out.println("A is first method");
}
}
class B extends A{
void showB(){
System.out.println("B is Second method");
}
}
class Cc extends A{
void showC(){
System.out.println("C is third method");
}
public static void main(String args[]){
System.out.println("_____Hierarchical inheritance_____");
Cc obj = new Cc();
obj.showC();
obj.showA(); 
System.out.println(" ");
B obj1= new B();
obj1.showB();
obj1.showA();  
}
}