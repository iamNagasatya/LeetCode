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
    int preidx = 0;
    unordered_map<int, int> mp;

    TreeNode * construct(vector<int>& preorder, vector<int>& inorder, int s, int e){
        if(s>e) return nullptr;

        TreeNode * root = new TreeNode(preorder[preidx++]);
        
        int index = mp[root->val];

        root->left = construct(preorder, inorder, s, index-1);
        root->right = construct(preorder, inorder, index+1, e);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return construct(preorder, inorder, 0, preorder.size()-1);
    }
};