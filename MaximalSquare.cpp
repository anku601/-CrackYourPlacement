class Solution {
public:
    int solve(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp,int n ,int m){
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }   
        int right=solve(matrix,i,j+1,maxi,dp,n,m);
        int diagonal=solve(matrix,i+1,j+1,maxi,dp,n,m);
        int down=solve(matrix,i+1,j,maxi,dp,n,m);
        
        int curr =0;
        if(matrix[i][j]=='1'){
             curr = 1 + min(right , min(down, diagonal));
             dp[i][j] = curr;
             maxi = max(maxi ,curr);
            return curr;
        }
        else{
            return dp[i][j]=0;
        }
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
         int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        solve(matrix,0,0,maxi,dp,n,m);
        return maxi*maxi;
    }
};