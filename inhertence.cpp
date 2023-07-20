#include <iostream>
using namespace std;

// class child_class: access_modifier parent_class{}

//parentclass k private member cannot be accessed by any modifier in subclass (hidden)
//parent class k public member are accessed and inherited the way modifiers are specfied

//protected of parent class ko private m privately inherit
//protected of parent class ko public m protectedly inherit

//protected is like private only but we can access it in our class and not outside
//it can be accessed inside child class also but not in intmain



class Human
{

    private:
     int rollno;
public:
    int height;
    int weight;
    int age;

public:


    int getAge()
    {
        return this->age;
    }
    int getWeight()
    {
        return this->weight;
    }
    int getrollno()
    {
        return this->rollno;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
    void setrollno(int n)
    {
        this->rollno = n;
    }
};

class Male : public Human//publically sare properties and fxns ayege
//is class m wo public m ayega
{

public:
    string color;

    void sleep()
    {
        cout << "male is sleeping" << endl;
    }

    // void setrollno(int n)
    // {
    //     this->rollno = n;
    // }//will give error as it uses roll no which is not here inherited and inaccessible
    //but if it was protected (rollno) then it can be Accessed here (not in int main)
};

int main()
{

    Male object1;

    object1.setWeight(55);//setweight is inherited inside male class

    cout<<object1.getWeight()<<endl;

    cout<<object1.color<<endl;
    object1.sleep();

    object1.setrollno(43);
    cout<<object1.getrollno();//no error as getter and setter use kia inside main class (where pvt member is declared)

   // cout<<object1.rollno;//error dega as it is private
}