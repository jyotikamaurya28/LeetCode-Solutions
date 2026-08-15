class Solution {
    int count = 0;
    int res;

    void inorder(TreeNode* node, int k) {
        if (!node) return;
        inorder(node->left, k);
        count++;
        if (count == k) {
            res = node->val;
            return;
        }
        inorder(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};