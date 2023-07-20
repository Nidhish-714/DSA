#include <iostream>
using namespace std;
#include "hero.cpp"

// class is custom userdefined dt type

// class hero {
// //empty class has only 1 byte of memory
//     //properties
//     char name [20];
//     int health;
//     char level;
// };

// dusri file is import karaya

// access modifiers
// public,private,protected
// bydefault it is private
//  public  - >  can access anywhere (inside and outside class)

int main()
{

    hero nidhish; // object bana dia in static way
    nidhish.health = 99;
    nidhish.setlevel('b', 'c'); // accessed an private property using fxn(fxn is public)

    cout << "size " << sizeof(nidhish) << endl;
    cout << "health is " << nidhish.health << endl;
    // cout<<print();//error as it uses level which is private

    cout << "nidhish level is when it is in private : " << nidhish.getlevel() << endl;

    hero *b = new hero; // dynamiccaly

    (*b).setlevel('b', 'f');
    cout << "b level is " << (*b).getlevel()<<endl;

    hero *c = new hero;
    c->setlevel('b','q');
    cout<<"*c level with arrow operator is : "<<c->getlevel()<<endl;

    //whenever we create an object ,a constructor is called hero()
    //invokes at time of object creation  (nidhish.hero())
    //when class is created a default constructor is also created
    //no return type and no parameter required 

    //when we create a constructor then compiler se bana hua constructor hat jayega

    hero ramesh(10);
    ramesh.sethealth('a',50);

    cout<<"address of ramesh is"<<&ramesh<<endl;
    cout<<"health of ramesh is  "  <<ramesh.gethealth();
    cout<<endl;
    hero jethlal(80,'j',"jetha");
    jethlal.print();

    //when we create a constructor , compiler wala constructor khtm hota
    //islie whenever making an object see parameters



    //copy constructor
    char name1[8]="nidhish";
    hero S(70,'A',name1);
    S.print();

    hero R(S);//same only
    R.print(); 
    //R.health = S.health
    //R.level = S.level

    hero hero1(12, 'D',name1);
    char name[7]= "babbar";
    hero1.setname(name);

    hero1.print();

    hero hero2(hero1);
    hero2.print();


    hero hero3(40,'H',name);

    hero2 = hero3;
    hero2.print();
    hero3.print();


    return 0;
}