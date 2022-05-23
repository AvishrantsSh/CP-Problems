class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        auto pre = root;
        while(pre->left) {
            for(auto cur = pre; cur; cur = cur->next) {
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
            }
            pre = pre->left;
        }
        return root;
    }
};