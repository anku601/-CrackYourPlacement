class Solution{
    public:
     long long solve(vector<long long>&a,int i,int j){
          if(j>=a.size())
            return LONG_MAX;
        return min(a[j]-a[i] , solve(a,i+1,j+1));
     }
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
        
        return solve(a,0,m-1);
    
    }   
};