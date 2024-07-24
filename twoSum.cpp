class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int ln =nums.size()-1;
       // int sum=0;
        for(int i=0;i<=ln ;i++){
            for(int j=i+1;j<=ln;j++){
               if( nums[i]+nums[j]== target){
                 return {i,j};
               }
            }

        }
        return {};
       
        
    }
};