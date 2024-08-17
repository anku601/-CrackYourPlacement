//tabulation method

class Solution {
public:
#include <vector>
int solve2(vector<int>&days,vector<int>&cost){
    int n= days.size();
    vector<int>dp(n+1,INT_MAX);
    dp[n] =0;

    for(int k=n-1; k>=0; k--){
        int oneDay = dp[k+1] +cost[0];
    
        int i;
        for(i=k; i<n && days[i]<days[k]+7; i++);
        int oneWeeks =dp[i] + cost[1];

        for(i=k; i<n && days[i]<days[k]+30; i++);
        int oneMonth = dp[i] +cost[2];
    
        dp[k]=min(oneDay, min(oneWeeks, oneMonth));
    }
    return dp[0];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         
         return solve2(days,costs);
        
    }
};


  // Recursion +memorization 


    
#include <vector>
int solve1(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
    // base case
    if(index >= n){
        return 0;
    }
    if(dp[index] != INT_MAX){
        return dp[index];
    }
    //for day 1
    int oneDay = solve1(n,days,cost,index+1,dp) +cost[0];
    // for day 7
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int oneWeeks = solve1(n, days, cost, i,dp) + cost[1];
    //for day 30
    for(i=index; i<n && days[i]<days[index]+30; i++);
    int oneMonth = solve1(n, days, cost, i,dp) +cost[2];
    
    dp[index]= min(oneDay, min(oneWeeks, oneMonth) );
    return dp[index];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,INT_MAX);
     returnsolve1(n,days,cost,0,dp);
}
    