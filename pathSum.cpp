class Solution {
private:
    bool findPath(int sum, int targetSum, TreeNode* root) {
        if(!root) 
            return false;

        if(!root->left && !root->right) {
            return sum+root->val == targetSum;
        }

        bool left = findPath(sum+root->val,targetSum,root->left);
        bool right = findPath(sum+root->val,targetSum,root->right);

        return left | right;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return findPath(0,targetSum,root);
    }
};