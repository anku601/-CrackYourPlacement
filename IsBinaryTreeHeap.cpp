class Solution {
  public:
  int countNodes(struct Node* tree){
      if(tree==NULL){
          return 0;
      }
      
      int ans =1+countNodes(tree->left)+countNodes(tree->right);
      return ans;
  }
  bool isBST( struct Node* tree, int index, int cnt ){
      if(tree ==NULL){
          return true  ;
      }
      
      if(index>=cnt){
          return false;
      }
      else{
          bool left= isBST(tree->left, 2*index+1,cnt);
          bool right= isBST(tree->right, 2*index+2,cnt);
          return (left && right);

      }
  }
  
  bool maxOrder(struct Node* root){
      if(root->left==NULL && root->right==NULL){
          return true;
      }
      
      if(root->right==NULL){
          return (root->data > root->left->data);
      }
      else{
          bool left = maxOrder(root->left);
            bool right = maxOrder(root->right);
        
        return (left&& right &&
        (root->data> root->left->data && root->data > root->right->data));
      }
  }
  
    bool isHeap(struct Node* tree) {
        int index= 0;
        int totalCount = countNodes(tree);
        
        if(isBST(tree,index,totalCount) && maxOrder(tree)){
            return true ;
        }
        else{
            return false;
        }
        
    }
};