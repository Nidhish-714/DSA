#include<iostream>
using namespace std;

//------encapsulation-------//
//for info and data hiding
//wrapping up datamember and functions

//datamember -> properties
//functions -> methods

//fully encapsulated class - all datamembers are private

//why? -> for data hiding, security,if we want we can make class 'read only'
// for unit testing



//------inheritance------//
//inherit some fxns in other class
//parentclass and child class

//class child_class: access_modifier parent_class{}

class Student {

    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }

    int getHeight(){
        return this->height;
    }
};


int main(){

    Student first; 



}