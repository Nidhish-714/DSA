// map<node,int> m; key value element
#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>

int main()
{

    // creation
    unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);
    // 2
    pair<string, int> p2 = make_pair("love", 3);
    m.insert(p2);
    // 3
    m["mera"] = 1; // creation
    m["mera"] = 2; // updation

    // searching
    cout << m["mera"] << endl;
    cout << m.at("mera") << endl;

    // but
    cout << m["unknownkey"] << endl;    // gives 0 and make new map //banana
    cout << m.at("unknownkey") << endl; // give 0 as it is created //dikhana

    //  cout << m.at("unknownkeynew") << endl; // gives a fault as not created//dikhana
    cout << m["unknownkeynew"] << endl; // gives 0 //banana

    cout << "size is " << m.size() << endl;
    cout << "count is " << m.count("love") << endl; // 1 //present
    cout << "count is " << m.count("bro") << endl;  // unknown ko 0 dia //absent

    // erase
    m.erase("love");
    cout << "size is " << m.size() << endl;

    for (auto i : m)
    {
        cout << i.first << " and " << i.second << endl;
    }

    // unorder map me complexity se constant
    // map is log(n) hota hai

    cout << endl;

    // iterator

    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " and " << it->second << endl;
        it++;
    } // random order me print as unordder

    // if it was orderd map then jis order me enter usi order me print

    return 0;
}

// max frequency
// map<number,count>

int maxFrequency(vector<int> &arr, int)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break; // if same number has same frequency then return number with lowest index
        }
    }
    return maxAns;
}

// bucket array
// hash code koi bhi object ko int me convert karega
// hash code se jo number mila usko us range me lane ka kaam hai compre
// function ka by %
// if hashcode alag object string ko same number me convert kia then it is collision
// isliye we have to do open handling and closed addressing for collision handling

// open hashingg -- same place pr jao 
// us block me linked list ka head store hota hai and in collision dono
// elements us linked list me jate hai --aka seperate chaining


// open addressing -- agli khali jgah daldo during collision
// and this agli jgah is given by a function Hi(a)=h(a)+Fi(a)-- ith attempt me kaha place krna hai
// linear probing -- F(i) = i
// quadratic probing -- F(i) = i^2

// no of enteries in a box -> n/b ---load factor  ( n = number of words)
// we ensure that load factor is less than 0.7

// if n increases then do rehashing (increase bucket size or do loadfactor by half)
