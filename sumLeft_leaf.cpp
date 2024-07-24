class Solution {
   void solve(TreeNode *root, vector<int>&v ){
        
        if(root ==NULL ){
            return ;
        }

        solve(root->left,v);
         solve(root->right,v);
        
    if(root->left && !root->left->left && !root->left->right){
       v.push_back(root->left->val);
    }
       
}
public:
    int sumOfLeftLeaves(TreeNode* root) {
    
    
    vector<int>v;
    solve(root, v);
    int ans=0;
    int i=0;
    int ln=v.size()-1;
    while(i<=ln){
        ans=ans+v[i];
        i++;
    }
    return ans;

        
    }
};