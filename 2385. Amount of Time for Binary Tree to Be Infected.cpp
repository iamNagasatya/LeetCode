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
    pair<int, bool> solve(TreeNode * root, int start, int & ans){
        if(!root) return {-1, false};
        pair<int, bool> lp = solve(root->left, start, ans);
        pair<int, bool> rp = solve(root->right, start, ans);
        
        if(root->val == start){
            ans = max(ans, 1 + max(lp.first, rp.first));
            return {0, true};
        }

        if(!lp.second && !rp.second){
            return {1  + max(lp.first, rp.first), false};
        }

        if(lp.second){
            ans = max(ans, lp.first + rp.first + 2);
            return {lp.first + 1, true};
        }
        if(rp.second){
            ans = max(ans, lp.first + rp.first + 2);
            return {rp.first + 1, true};
        }
        return {0, false};

    }
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        solve(root, start, ans);
        return ans;
    }
};