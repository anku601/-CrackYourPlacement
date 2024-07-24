        
        //Range Sum of BST


class Solution {
    private:
    void solve(TreeNode* root, int low, int high,vector<int>& v){
        
        if(root==NULL){
            return ;
        }


        if(root->val >= low && root->val <= high){
            v.push_back(root->val);
        }
        solve(root->left,low,high,v);
        solve(root->right,low,high,v);

    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        vector<int> v;
        solve(root,low,high,v);

        int sum=0;

        for(int i=0 ;i<=v.size()-1;i++){
            sum=sum+v[i];
        }
        return sum;
    }
};