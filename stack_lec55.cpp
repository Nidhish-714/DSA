#include <iostream>
#include <stack>
#include <string>
using namespace std;
// reverse a string using stack
// stack me char dalkar wapis pop krege then reverse hojayega

// delete middle elemnets from stack
// stack. size /2 se middle elemnt nikalo

// or

// recursion

void delmid(stack<int> &stack, int count, int size)
{
    if (size / 2 == count)
    {
        stack.pop();
        return;
    }

    else
    {
        int num = stack.top();
        stack.pop();
        delmid(stack, count + 1, size);
        stack.push(num);
    }
}

// valid parenthesis

// {()}--_Valid_
// {(})--notvalid

// deko corresponding parenthesis present hai kya , if present then pop it
//  and if stack is empty then valid

// bool matches(char top , char param){
//     if(top==param){
//         return 1;
//     }else{
//         return 0;
//     }
// }

bool validparenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening bracket ,stack push
        // if closing bracket , stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch); // for opening
        }
        else
        {
            // for closing

            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
}

// insert element at bottom
void insert_at_bottom(stack<int> &stack, int count, int size, int val)
{
    if (size == count)
    {
        stack.push(val);
        return;
    }

    else
    {
        int num = stack.top(); // pop hone k bad wapis insert kr skae islie store krdo
        stack.pop();
        insert_at_bottom(stack, count + 1, size, val);
        stack.push(num);
    }
}
// reverse a stCK using recursion

void insertAtBottomForReverse(stack<int> &stack, int num)
{
    // basecase
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    else
    {
        int n = stack.top();
        stack.pop();    
        insertAtBottomForReverse(stack, num);
        stack.push(n);
    }
}

void reverseRecursion(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    else
    {
        int num = stack.top(); // pop hone k bad wapis insert kr skae islie store krdo
        stack.pop();
        reverseRecursion(stack);
        insertAtBottomForReverse(stack, num);
    }
}

// sort in stack
// rec se akhri elem tk gaye and udhr se unki sorted place pr insert kie

// do sorted insert

void sortedInsert(stack<int> &stack, int num)
{
    // base case

    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // rec call
    sortStack(stack);
    sortedInsert(stack, num); // correct place pr insert kia
}

// redundant bracket
// ((a+b)) -- no need of extra bracket islie redundant
// bracket k bich me operator hona

bool isRedundantBrackets(string &str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        else
        {
            // ya to ) hoga ya koi charcater like a b c d

            if (ch == ')')
            {
                bool isRedundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '/' || top == '*')
                    {
                        isRedundant = false; // bich me operator hai ( idhr )
                    }
                    s.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }
                s.pop(); //( ye haatane ko jo top pr hai('('))
            }
        }
    }
    return false;
}

int main()
{
    string str1 = "babbar";
    stack<char> s1;

    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        s1.push(ch);
    }

    string ans = "";

    while (!s1.empty())
    {
        char ch = s1.top();
        ans.push_back(ch);
        s1.pop(); // taki s empty ho
    }

    cout << " ans is" << ans << endl;

    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }

    //////////
    cout << endl;
    cout << endl;
    cout << endl;
}
