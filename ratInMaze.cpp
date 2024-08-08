#include <bits/stdc++.h> 
bool isSafe(int i, int j,vector < vector < int >> & arr, int n,vector<vector<bool>> &visited ){
    if((i>=0 && i<n) && (j>=0 && j<n ) && arr[i][j]==1 && visited[i][j]!=1)
        return true;
    return false;
}

void solve(int i, int j,vector < vector < int >> & arr, int n,vector<string> &ans,vector<vector<bool>>& visited, string path  ){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return ;
    }

    visited[i][j] = 1;
    // Down
    if(isSafe(i+1, j, arr, n, visited)){
        solve(i+1, j, arr, n, ans, visited,path+'D');
    }


    // Left
     if(isSafe(i, j-1, arr, n, visited)){
        solve(i, j-1, arr, n, ans, visited,path +'L');

    }


    // Right
     if(isSafe(i, j+1, arr, n, visited)){
        
        solve(i, j+1, arr, n, ans, visited,path+'R');
       
    }


    // Up
    if(isSafe(i-1, j, arr, n, visited)){
        
        solve(i-1, j, arr, n, ans, visited, path+'U');
       
    }
     visited[i][j] = 0;
}


vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));


    if(arr[0][0]!=1)
        return ans;


    solve(0, 0, arr, n, ans, visited,path);
    return ans;
}
