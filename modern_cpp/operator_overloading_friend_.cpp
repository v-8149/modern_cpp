#include <iostream>
//Operator must return the same type as declared
//If you compute a primitive (int), convert it back to object
class MyClass{
int *ptr;
public:
MyClass(int value){
ptr=new int(value);
}
MyClass(const MyClass &other){
ptr=new int(*other.ptr);
}
MyClass& operator=(const MyClass &other){
if(this != &other){
delete ptr;
ptr = new int(*other.ptr);
}
return *this;
}
friend MyClass operator+(const MyClass& a,const MyClass& b){
return MyClass(*a.ptr+*b.ptr);
}
~MyClass(){
delete ptr;
}
void Display(){
std::cout<<*ptr<<std::endl;
}
};
int main() {
MyClass a(20),b(30);
MyClass c = a+b;
c.Display();
return 0;
}