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
    void inorder(TreeNode * root, int hd, int vd, map<int, map<int, vector<int>>> &mp){
        if(!root) return ;
        inorder(root->left, hd-1, vd+1, mp);
        mp[hd][vd].push_back(root->val);
        inorder(root->right, hd+1, vd+1, mp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> mp;
        inorder(root, 0, 0, mp);
        for(auto hdp : mp){
            vector<int> cols;
            for(auto vdp : hdp.second){
                sort(vdp.second.begin(), vdp.second.end());
                for(auto x: vdp.second) cols.push_back(x);
            }
            res.push_back(cols);
        }
        return res;
    }
};