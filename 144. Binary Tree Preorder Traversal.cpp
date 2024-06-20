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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            ans.push_back(root->val);
            if(root->left){
                TreeNode * lr = root->left;
                while(lr->right != nullptr) lr = lr->right;
                lr->right = root->right;
                TreeNode * temp = root;
                root = root->left;
                temp->left = nullptr;
            }
            else{
                root = root->right;
            }
        }
        return ans;
    }
};