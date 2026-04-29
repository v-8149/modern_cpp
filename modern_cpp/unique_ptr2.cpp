#include <iostream>
#include <memory>

int main() {
auto ptr=std::make_unique<int>(20);
//ptr is unique ptr of data type int
std::cout<<*ptr;
return 0;
}

int main() {
auto ptr=std::make_unique<int>(20);
*ptr= 30;
std::cout<<*ptr<<std::endl;
auto ptr2=std::make_unique<int>(50);
std::cout<<*ptr2<<std::endl;
//  ptr=ptr2;  //not allowed gives error
*ptr=*ptr2;   //allowed
std::cout<<*ptr<<std::endl;
return 0;
}

int main() {
auto ptr=std::make_unique<int>(20);
*ptr= 30;
std::cout<<*ptr<<std::endl;
auto ptr2=std::make_unique<int>(50);
std::cout<<*ptr2<<std::endl;
ptr=std::move(ptr2); //transfer of ownership is allowed
std::cout<<*ptr<<std::endl;
std::cout<<*ptr2<<std::endl;//error bcoz it becomes nullptr
return 0;
} 