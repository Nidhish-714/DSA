#include<iostream>
#include<vector>
using namespace std;

//2 - a b c
//3 - d e f
//23 - ad ae af , bd be bf , cd ce cf 

void solve(string digit,string output,int index,vector<string>&ans,string mapping[]){
    //base case
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';//to store it in int ('c'-'0' = 3)
    string value = mapping[number];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digit,output,index+1,ans,mapping);
    }
}


vector<string> lettercomb(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }
    string output = "";
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits , output ,index , ans , mapping);

}
int main(){


    return 0;
}