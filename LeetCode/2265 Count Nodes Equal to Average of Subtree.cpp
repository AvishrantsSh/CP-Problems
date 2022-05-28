class Solution {
public:
    int count = 0;
    pair<int,int> sumTree(TreeNode* root){
        if(!root) return {0,0};
        
        auto left=sumTree(root->left), right=sumTree(root->right);
        int sum = (left.first + right.first + root->val);
        int n = (left.second + right.second + 1);        
        count += ((sum/n)==root->val);
        return {sum,n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        auto p = sumTree(root);
        return count;
    }
};