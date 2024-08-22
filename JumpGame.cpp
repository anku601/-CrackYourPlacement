class Solution {
public:
    bool solve(vector<int>& nums ,int i, int n,vector<int>&dp){
        if(i==n){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        

        int maxjump=i+ nums[i];
            for(int j=i+1;j<=maxjump;j++){
                if(j<n+1 &&solve(nums,j,n,dp)){
                    return dp[i]=true;
                }
             }

        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size()-1;
        vector<int> dp(n+1,-1);

        return solve(nums, 0, n,dp);
    }
};