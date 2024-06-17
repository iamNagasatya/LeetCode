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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> level;

            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode * cur = s1.top();
                    level.push_back(cur->val);
                    s1.pop();
                    if(cur->left) s2.push(cur->left);
                    if(cur->right) s2.push(cur->right);
                }
            }
            else{
                while(!s2.empty()){
                    TreeNode * cur = s2.top();
                    level.push_back(cur->val);
                    s2.pop();
                    if(cur->right) s1.push(cur->right);
                    if(cur->left) s1.push(cur->left);
                }
            }

            ans.push_back(level);
        }
        return ans;
    }
};