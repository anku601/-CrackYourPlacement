class Solution {
private:
    void solve(TreeNode* root, TreeNode* &curr){
        if (root == NULL){
            return;
        }

        curr = root;
        TreeNode* right = root->right;

        curr->right = root->left;
        root->left = NULL;

        solve(root->right,curr);

        curr->right = right;

        solve(right,curr);
        return;
    }
public:
    void flatten(TreeNode* root) {
        
        solve(root, root);
    }
};