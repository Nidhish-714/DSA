#include <iostream>
using namespace std;

//if class A and class B has same functions and class C inherits
// both then which fxn will be called


class A{
    public:
    void func(){
        cout<<"printing class A func"<<endl;
    }
};
class B{
    public:
    void func(){
        cout<<"printing class B func"<<endl;
    }
};

class C:public A,public B{

};

int main(){
    C object1;
    object1.A::func();
    object1.B::func();

}