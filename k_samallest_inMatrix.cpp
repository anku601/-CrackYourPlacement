class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
          priority_queue<int> pq;
          int r= matrix.size()-1;
        
        for(int i=0;i<=r;i++){
            for(int j=0;j<=r;j++){
                pq.push(matrix[i][j]);
            }
        }
        
          while(pq.size()>k)
        {
            pq.pop();
        }
        return pq.top();
        
    }
};