#include<string.h>

class hero
{

public:

hero(){
    cout<<"constructor is called"<<endl;
}
    char name[20];
    int health;
   // char level;
    void print()
    {
        cout<<"name is"<< this ->name<<endl;
        cout <<"level is"<< this ->level << endl;
        cout << "health is "<< this ->health <<endl; // private members can be accessed anywhere inside class
    }

    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }

    void sethealth(char name, int n)//setter getter are used to access private member outside class
    {
        if (name = 'a')
        {
            health = n;
        }
    }
    void setlevel(char name, char ch)
    {
        //level = ch;
        if (name == 'b')//if name b ho then only set k lie if
        {
            level = ch;
        }
    }

    void print1()
    {
        cout << "this is public " << endl;
    }

    //parameterised constructor
    hero(int health ){
       this -> health = health;
       cout<<endl<<"this is"<<this<<endl;
       
       //property (data member) and input parameter name same then
    }//this stores address of our object
//this -> health is object ki health (ramesh.health jaise) and health is input parameter

    hero(int health , char level,char name[]){
        this->health = health;//this stores address
        this->level = level;
        strcpy(this ->name , name);
        cout << endl
             << "this is" << this << endl;
        cout << endl
             << "this is" << this << endl;
    }

    void setname(char name[]){
       strcpy( this -> name ,name);
    }



    //self made copy constructor

    hero(hero& temp){//&for pass by refrence
    cout<<"copy constructor called"<<endl;
       this -> health = temp.health;
       this -> level = temp.level;
       strcpy(this -> name , temp.name);

    }
private:
    char level;
};