class Solution {
    private:
    void solve(TreeNode *root, vector<int>&v ){
        
        if(root ==NULL ){
            return ;
        }

        solve(root->left,v);
        
         v.push_back(root->val);
        solve(root->right,v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        solve(root, v);

        return v;

        
    }
};