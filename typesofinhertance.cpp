//ek class se dusre class me inherit kia

#include <iostream>
using namespace std;


class Animal{
    public:
    int age;
    int weight;

    public:
    void bark(){
        cout<<"bark"<<endl;
    }
};

class Dog :public Animal{//single inhertance


};

class germanShepherd: public Dog{//multilevel inheritance 

};

class Human{
    public:
    string color;

    void speak()
    {
        cout << "speaking" << endl;
    }
};

class Hybrid:public Animal,public Human{//multiple inheritance (more than one class can inherit)

};

int main(){
    Dog d;
    d.bark();

    germanShepherd g;
    g.bark();

    Hybrid H;
    H.speak();
    H.bark();
}