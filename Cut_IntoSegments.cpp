#include <bits/stdc++.h>
// Recurssion +Memorization



int solve(int n,int x,int y,int z,vector<int>&dp){

        if(n==0){

            return 0;

        }

        if(n<0){

            return INT_MIN;

        }

        if(dp[n]!=-1){

            return dp[n];

        }

        int a=1+solve(n-x,x,y,z,dp);

        int b=1+solve(n-y,x,y,z,dp);

        int c=1+solve(n-z,x,y,z,dp);

        
		dp[n]=max(a,max(b,c));

        return dp[n];

    }

int cutSegments(int n, int x, int y, int z) {

    // Write your code here.

        vector<int>dp(n+1,-1);

        int ans=solve(n,x,y,z,dp);

        return ans<0 ? 0 :ans;

}