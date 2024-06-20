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

const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void inorder(TreeNode * root, TreeNode * &prev, TreeNode * &l1, TreeNode * &l2){
        if(! root) return;
        inorder(root->left, prev, l1, l2);
        if(prev && prev->val > root->val){
            if(!l1) l1 = prev;
            l2  = root;
        }
        prev = root;
        inorder(root->right, prev, l1, l2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode * l1 = nullptr, *l2 = nullptr, *prev = nullptr;
        inorder(root, prev, l1, l2);
        int temp = l1->val;
        l1->val = l2->val;
        l2->val = temp;
    }
};