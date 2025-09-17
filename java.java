class BPUT{
void show(){
System.out.println("I am in BPUT");
}
}
class GCEK extends BPUT{
void show(){
System.out.println("I am in GCEK");
}
}
class CSE extends BPUT{
void show(){
System.out.println("I am a CSE Student.");
}
}
class C extends CSE{
void show(){
System.out.println("I am studying C programming.");
}
}
class Java extends CSE{
void show(){
System.out.println("I am studying Java programming.");
}
}

class ETC extends GCEK{
void show(){
System.out.println("I am a ETC Student.");
}
}
class DSP extends ETC{
void show(){
System.out.println("I am studying DSP.");
}
}
class AEC extends ETC{
void show(){
System.out.println("I am studying AEC");
}
}
class EE extends GCEK 


