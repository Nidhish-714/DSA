#include<iostream>
using namespace std;
#define PI 3.14
// macros 
// #define to create macros
//a piece of code in a program that is replaced by value of n

int main(){
    int r = 5;
    float pi =3.14;
    int area = 3.14*r*r;
    int area1 = pi*r*r;
    int area2 = PI*r*r;
   // PI = PI +1; //CANNOT DO
    cout<<area<<endl;
    cout<<area1<<endl;
    cout<<area2<<endl;

}

//#define AREA(l, b) (l * b)

// Driver Code
// int main()
// {
//     // Given lengths l1 and l2
//     int l1 = 10, l2 = 5, area;

//     // Find the area using macros
//     area = AREA(l1, l2);

//     // Print the area
//     cout << "Area of rectangle"
//          << " is: " << area;

//     return 0;
// }

// C++ program to illustrate macros
// #include <iostream>
// using namespace std;

// // Macro definition
// #define INSTAGRAM FOLLOWERS
// #define FOLLOWERS 138

// // Driver Code
// int main()
// {
//     // Print the message
//     cout << "Geeks for Geeks have "
//          << INSTAGRAM << "K followers on Instagram!";

//     return 0;
// }

// #include <iostream>
// using namespace std;
// #define PI 3.1416
// #define AREA(r) (PI * (r) * (r))

// int main()
// {

//     float r = 7; // radius of circle

//     cout << "Area of Circle with radius " << r << ": " << AREA(r);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// // Function-like Macro definition
// #define min(a, b) (((a) < (b)) ? (a) : (b))

// // Driver Code
// int main()
// {

//     // Given two number a and b
//     int a = 18;
//     int b = 76;

//     cout << "Minimum value between"
//          << a << " and " << b
//          << " is: " << min(a, b);

//     return 0;
// }