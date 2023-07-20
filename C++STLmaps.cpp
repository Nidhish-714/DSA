#include <iostream>
#include <map>
using namespace std;

/*
key value k form m store , every key is unique and points to single element
it is sorted when printing
*/

int main(){
    map<int,string>m;

    m[1] = "nidhish";
    m[2] = "wakodikar";

    m[13] = "anil";
    m.insert({5,"bheema"});

    for(auto i: m){
        cout<<i.first<<"   "<<i.second<<endl;

    }


    cout<<m.count(13)<<endl;

    cout<<"after erase"<<endl;
    m.erase(13);

        for(auto i: m){
        cout<<i.first<<"   "<<i.second<<endl;

    }

    auto it = m.find(5);
    // C++ map find() function is used to find an 
    // element with the given key value k. 
    // If it finds the element then it returns an 
    // iterator pointing to the element. Otherwise, 
    // it returns an iterator pointing to the end of the map, i.e.,
    // map::end().
    for(auto i =it ; i!=m.end();i++){
        cout<<(*i).first<<endl;
    }


}
