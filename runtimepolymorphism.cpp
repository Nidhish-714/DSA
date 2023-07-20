#include <iostream>
using namespace std;

//methods == functions (1)
//dynamic polymorphism,,method overriding

//rules --

// the method or fxn of parent class and method of child class must have same name name
// the arguments of parent class and arguments of child class must have same name
//possible through inheritence only

class Animal{
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    //fxn overriding
    void speak(){
        cout<<"barking"<<endl;
    }
};

int main(){
    Dog obj;
    Animal obj1;
    obj.speak();//dog ka object hai, idf dog me speak fxn nai hota then "speaking" ata
    obj1.speak();
}

