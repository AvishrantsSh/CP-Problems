/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, maxLevel = 0;
        deep(root, 0, maxLevel, sum);    
        return sum;
    }
    
    void deep(TreeNode *root, int level, int &maxLevel, int &sum){
        if(root){
            deep(root->left, level+1, maxLevel, sum);
            if(level > maxLevel){
                sum = 0;
                maxLevel = level;
            }
            if(level == maxLevel)
                sum += root->val;
            deep(root->right, level+1, maxLevel, sum);
        }
    }
};