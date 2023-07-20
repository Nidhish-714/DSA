#include<iostream>
#include<vector>
using namespace std;

bool issafe(int x, int y, int n, vector<vector<int>> visited,vector<vector<int>> &m){
    if((x>=0 && x<n)&&(y>=0 && y<n)&&(visited[x][y]==0 && m[x][y]==1)){
        return true;

    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y,vector<vector<int>> visited,string path){
      if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ; 
      }//reached x,y

      visited[x][y] = 1;
      //down
      int newx = x+1;
      int newy = y;
      if(issafe(newx,newy,n , visited,m)){
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
      }
      //left
       newx = x;
       newy = y-1;
      if(issafe(newx,newy,n , visited,m)){
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
      }
      //right
       newx = x;
       newy = y+1;
      if(issafe(newx,newy,n , visited,m)){
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
      }
      //up
      int newx = x;
      int newy = y-1;
      if(issafe(newx,newy,n , visited,m)){
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
      }
      visited[x][y]=0;//wapis 0 kar diaya taki new path k liye wapis zero hojaye
}