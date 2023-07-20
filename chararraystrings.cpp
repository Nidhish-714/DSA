#include <iostream>
#include <string.h>
using namespace std;
// null character encounter hone par break hoga

int length(char name[20])
{
    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }

    return i;
}

void reverse(char name[20], int n)
{
    int s = 0;
    int e = n - 1;
    swap(name[s++], name[e--]);
}

bool checkpalindrome(char name[20], int n)
{

    int s = 0;
    int e = n - 1;

    while (s >= e)
    {
        if (tolower(name[s]) != tolower(name[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

char tolower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isvalid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }

    return 0;
}

char getmax(string s)
{
    int arr[26] = {0};
    int number = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else{
            number = ch - 'A';
        }

        arr[number]++;
    }
int maxi = -1;
int ans = -1;
    for (int i = 0; i < 26; i++){
        if(arr[i]>maxi){
            maxi=arr[i];
            ans = i;
        }

    }

    char finalans = 'a'+ ans;
    return finalans;


}

int main()
{

    char name[20];
    cout << "enter your name" << endl;
    cin >> name;

    // reverse(name,length(name));
    // length(name);

    // name[2] = '\0';

    cout << "your name is" << endl;
    cout << name << endl;

    // nid anil me nid hi print karega
    // stops execution when it gets space or tab or enter

    // cout<<tolower('B');

    cout << "palindrome " << checkpalindrome(name, length(name)) << endl;

    string word;
    cout << "enter a string" << endl;

    cin >> word;

    cout<<getmax(word);
    /*
    use string str =""
    str.push_back
    str.length
    */


}
