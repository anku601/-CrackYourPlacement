//215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int> pq;

         int r=nums.size()-1;
        
        for(int i=0;i<=r;i++){
            pq.push(nums[i]);
        }
        
        int n= pq.size()-1;
        vector<int> v;
        for(int i=n;i>=0;i--){
            int ans = pq.top();
            v.push_back(ans);
            pq.pop();
        }
        return v[k-1];
    }
    
};