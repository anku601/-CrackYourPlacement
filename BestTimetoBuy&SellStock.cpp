  /// bekar solution


  class Solution {
public:
    int solve(vector<int>& price,int i,int n){

        if(i>n){
            return 0;
        }
        int ans=0;
        int sub;


        for (int j=i+1;j<n;j++){
            if(price[i]>=price[j]){
                break;
            }
            else{
            sub= (price[j]-price[i]);

            }
            ans=max(ans,sub);
        }
        //solve(prices,i+1,n);
        return max(ans,solve(price,i+1,n));
    }
    int maxProfit(vector<int>& prices) {

        int n= prices.size();
       return solve(prices, 0, n);
        
    }
};



    //  best solution 


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
}; 