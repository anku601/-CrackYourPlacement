class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int mx=nums[0];
        int mn=nums[0];

        for(int i=1;i<n;){
            while(i<n && nums[i]>=nums[i-1]){
                mx=nums[i];
                i++;
            }
            ans+=mx-mn;
            while(i<n && nums[i]<=nums[i-1]){
                mn=nums[i];
                i++;
            }
        }
        return ans;
    }
};