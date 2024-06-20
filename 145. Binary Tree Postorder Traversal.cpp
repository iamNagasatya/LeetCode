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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode * > stk;
        if(root) stk.push(root);

        while(!stk.empty()){
            TreeNode * cur = stk.top();
            ans.push_back(cur->val);
            stk.pop();

            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }

        reverse(ans.begin(), ans.end());

        
        return ans;
    }
};