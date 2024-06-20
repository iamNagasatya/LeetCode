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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode * cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode * lr = cur->left;
                while(lr->right != nullptr) lr = lr->right;
                lr->right = cur;
                TreeNode * temp = cur;
                cur = cur->left;
                temp->left = nullptr;
                
            }
        }
        return ans;
    }
};