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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * new_node = new TreeNode(val);
        if(!root) return new_node;
        
        TreeNode * par = nullptr, * cur = root;
        while(cur){
            par = cur;
            if(val<cur->val){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }

        val < par->val ? par->left = new_node : par->right = new_node;

        return root;
    }
};