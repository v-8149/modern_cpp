#include <iostream>
#include <memory>
class Test{
public:
int num;
Test(int val){
num=val;
std::cout<<"parameterized constructor"<<std::endl;
}
~Test(){
std::cout<< "destructor"<<std::endl;
}
};
int main() {
auto ptr = std::make_unique<Test>(20);
std::cout<<"memory address of Test object is: "<<ptr.get()<<std::endl;
std::cout<<"data of object is: "<<ptr->num<<std::endl;
//std::cout<<ptr<<std::endl;//error
}