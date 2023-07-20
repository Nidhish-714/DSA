#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// hardd que series

// next smaller element--->first smaller element

// 2  1  4  3 ----i/p
// 2 ka next smallest is 1 uske age , 1 ka koi smallest nai to -1
// 1 -1  3 -1 ----o/p

// approach 1 -- do 2 for loops
// approach 2 -- traverse from back in stack

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() >= curr)
        {
            s.pop();
        }

        // ans is stack ka top

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

// largest rectangular area in histogram

vector<int> nextSmallerElement2(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top

        ans[i] = s.top();
        s.push(i); // taki next time usse compare hoo
    }

    return ans;
}
vector<int> prevSmallerElement2(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top

        ans[i] = s.top();
        s.push(i); // taki next time usse compare hoo
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement2(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement2(heights, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        { // sare bade element hai uske age
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

// celebrity problem
// everyone knows celebrity
// celebrity knows no one
// person are 0 1 2
// diagnoal part ignore kro
//    0  1  2
//
// 0   0  1  0
// 1   0  0  0
// 2   0  1  0     1 is celebrity

// 0 knows 1
// 2 knows 1
// 1 knows noone --- celebrity

// rows is celebrity (us row me sab zero )
// and
// us wale number k column me sab 1 (except diagonal)
// approach 1 - sab element k lie unka row and column check karra hu

// approach 2 - stack k end me celebrity bachega

// enter all members in stack
// jabtak size is not equal  to one tab tak pop kro ( pele two elements hi )
// if a knows b ( a is not a celebrity , b ko push krdo)
// if b knows a ( b is not a celeb , a ko push krdo)
// jo ek single element hai stack m vo hoskta hai shyad celeb ho
// verify
// celeb knows no one - row check kro uska (000 hona)
// and column check kro sare 1 hone chaie except khudka

bool knows(vector<vector<int>> &M, int a, int b, int n)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    // step 1 -- push all elements
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2 --

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int candidate = s.top();

    // step 3 -- verify celeb

    bool rowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount == n)
    {
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

// max rectangle in binary matrix with all 1's
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// max area is of 8

// compute max-area for 1st row
// for every remaining row , upper row k elements add kro in current row
// area compute kro

// N stacks in an array
// approach 1 is to divide array in n parts and apply push and pop

// approach 2
// let size is 9 and stacks is 3
// top[]--represents top of that  stack
// next[]--point to next free space if(arr[i]) not something / else--(something stored) point to next element after top (niche ka in stack)
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N; // no of stack
        s = S; // size of arr
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index value to -1
        next[s - 1] = -1;

        // initialise freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next;
        next[index] = top[m - 1]; // uske niche ka element (here top not updated yet)previous top

        // update top now
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

// get min element in O(1) tc and sc

// approach 1
// int mini =int max
// mini=min(mini,curr) and store it in second stack and return top of second  stack
// curr--stack ko traverse krega pop krega dsure stack me ---- O(N)

// approach 2
// push operation
// overflow check
// for 1st element -- normal push,mini update
// if (curr<mini){
//     val = 2*curr - mini
// }--- push -- and update mini(with curr mini)
// else normal push in stack

// pop opertion
// underflow check
// if(curr>mini){
//     normal pop()
// }else{
//     val = 2*mini - curr
//     mini = val
//     pop
// }

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }

        else
        {
            if (data < mini)
            {
                int val = 2 * data - mini;
                s.push(val);
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevmini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevmini;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isempty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
    }
};
