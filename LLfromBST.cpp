// Flatten BST To A Sorted List

void findinOrder(TreeNode<int>* root,vector<int>&inorderval){
     if(root==NULL){
         return ;
     }

     findinOrder(root->left,inorderval);
     inorderval.push_back(root->data);
     findinOrder(root->right,inorderval);

 }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderval;
    findinOrder(root,inorderval);

    TreeNode<int>* newRoot = new TreeNode<int>(inorderval[0]);

    TreeNode<int>* curr = newRoot;

    int n= inorderval.size();

    for(int i=1;i<n;i++){
        TreeNode<int>*temp = new TreeNode<int>(inorderval[i]);
        curr->left = NULL;
        curr->right= temp;

        curr=temp;
    }
    
    curr->left= NULL;
    curr->right= NULL;

    return newRoot;

}