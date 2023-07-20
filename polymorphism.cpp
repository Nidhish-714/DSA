//exsisting in many forms


//compile time polymorphism---

//1 function overloading
//2 operator overloading


#include <iostream>
using namespace std;

class A{

    public:

    //function overloading
    void sayHello(){
        cout<<"helloo Nidhish"<<endl;
    }
    void sayHello(string name){
        cout<<"helloo "<<name<<endl;
    }//same name but arg different (two exact same fxn can not be written)
    //can overload function (same name se function bana h,then change arg type)
};

class B{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

//operator overloading
    void operator+ (B &obj){
        int value1 = this->a;//first or current ka (obj1)
        int value2  = obj.a; //input ka a value
        cout<<"output "<<value2-value1<<endl;
    }

    void operator()()
    {
        cout << "mai () wala operator hu "<<this->a << endl;
    }
};

int main(){
    A obj;
    obj.sayHello();
    obj.sayHello("nidhish");

    B obj1,obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;//obj1 is current and obj2 is input
    //this will call operator+ function

    obj1();//()wala call

}