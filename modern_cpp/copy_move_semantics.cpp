#include <iostream>
class MyClass{
   int *ptr;
   public:
   MyClass(){
      ptr = new int(0);
   }
    MyClass(int value){
        ptr =new int (value);
    }
    MyClass (const MyClass &other){
        std::cout<<"Copy Constructor"<<std::endl;
        ptr = new int (*other.ptr);
    }
    MyClass operator +(const MyClass &obj){
        MyClass temp;
        std::cout<<"*ptr is "<<*ptr<<std::endl;
        std::cout<<"*obj.ptr is "<<*obj.ptr<<std::endl;
        *temp.ptr =  *ptr + *obj.ptr;
        return temp;
    }
   MyClass& operator =(const MyClass &obj){
       std::cout<<"copy assignment"<<std::endl;
        if(this != &obj){
        delete ptr;
        ptr = new int(*obj.ptr);
        }
        return *this;
    }
    MyClass (MyClass &&a){
        ptr = a.ptr;
        a.ptr=nullptr;
        std::cout<<"Move constructor"<<std::endl;
    }
    MyClass& operator=(MyClass &&a){
        std::cout<<"Move Assignment"<<std::endl;
        if(this != &a){
            delete ptr;
            ptr=a.ptr;
           a.ptr=nullptr;
        }
        return *this;
    }
    ~MyClass (){
        delete ptr;
    }
    void Display(){
        std::cout<<*ptr<<std::endl;
    }
};

int main(){
     MyClass c1(10);
     //MyClass c2=c1;
     MyClass c2(20);
     c1.Display();
     c2.Display();
     MyClass c3 = c2+c1;
     c3.Display();
     MyClass c4(40);
     c4 = c2;
    // c4=c4; //gives garbage value so we need to add 1 if condition
     c4.Display();
     MyClass c5 = std::move(c4);
     c5.Display();
     MyClass c6=MyClass (70);
     c6.Display();
     MyClass c7(100);
     c7=std::move(c6);
     c7.Display();
}
