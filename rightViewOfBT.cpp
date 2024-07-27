class Solution {
    private:
    void solve(TreeNode*root,vector<int> &ans,int lev){
    if(root==NULL){
        return ;
    }
    
    if(lev== ans.size()){
        ans.push_back(root->val);
    }
    solve(root->right,ans,lev+1);
    solve(root->left,ans,lev+1);
    
    
    
}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
   solve(root,ans,0);
   return ans;
    }
};