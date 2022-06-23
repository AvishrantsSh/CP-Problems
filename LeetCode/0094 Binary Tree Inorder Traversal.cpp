// Recursive Solution
class Solution {
public:
    vector<int> trav;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        trav.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return trav;
    }
};

// Iterative Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode *> st;
        while(root or !st.empty()){
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
};