class Solution {
private:
void inorder(TreeNode* curr, TreeNode*& prev, int& ans)
{
   
    // Base-case
    if (curr == NULL)
        return;
   
    // Calling in-order on the left sub-tree
    inorder(curr->left, prev, ans);
   
    if (prev != NULL)
        ans = min(curr->val - prev->val, ans);
    prev = curr;
   
    // Calling in-order on the right sub-tree
    inorder(curr->right, prev, ans);
}

public:
    int getMinimumDifference(TreeNode* root) {
            // Pointer to previous node in the
    // in-order traversal of the BST
    TreeNode* prev = NULL;
   
    // To store the final ans
    int ans = INT_MAX;
   
    // Call in-order for the BST
    inorder(root, prev, ans);
   
    // Returning the final answer
    return ans;
    }
};