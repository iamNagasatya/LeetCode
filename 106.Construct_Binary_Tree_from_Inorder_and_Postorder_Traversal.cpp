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
    int postidx;

    TreeNode * construct(vector<int> & in, vector<int> & post, int s, int e, map<int, int> &mp){
        if(s>e) return nullptr;
        TreeNode * root = new TreeNode(post[postidx--]);
        int index = mp[root->val];
        root->right = construct(in, post, index+1, e, mp);
        root->left = construct(in, post, s, index-1, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postidx = n - 1;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return construct(inorder, postorder, 0, n-1, mp);
    }
};