class Solution {
    private:
    int hight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHight =hight(root->left); 
        int leftRight = hight(root->right);
        return max(leftHight,leftRight)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 =diameterOfBinaryTree(root->right);

        int op3 = hight(root->left)+hight(root->right);

        return max(op3,max(op1,op2));
        
    }
};