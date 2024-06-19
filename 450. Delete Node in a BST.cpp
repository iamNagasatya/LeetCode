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
    TreeNode * getSuccessor(TreeNode * cur){
        cur = cur->right;
        while(cur && cur->left) cur = cur->left;
        return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left){
                TreeNode * temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else if(!root->right){
                TreeNode * temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            else{
                TreeNode * successor = getSuccessor(root);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};