#include <iostream>
using namespace std;

class MyClass {
int x;

public:
MyClass(int value) {
cout << "Constructor called\n";
x = value;
}

int GetValue() {
    return x;
}

void SetValue(int value) {
    x = value;
}

};

void Display(MyClass* p) {
if (!p) return;
cout << p->GetValue() << endl;
}

MyClass* GetPointer(int value) {
MyClass* p = new MyClass(value);
return p;
}
//-> .

void Operate(int value) {
MyClass* p = GetPointer(value);

if (p == nullptr) {
    p = new MyClass(value);
}

p->SetValue(100);
Display(p);

delete p;
p = nullptr;

}

int main() {
Operate(50);
//myclass *obj
}