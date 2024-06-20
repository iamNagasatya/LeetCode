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
    TreeNode * buildTree(vector<TreeNode *> &arr, int l, int h){
        if(l>h) return nullptr;
        int mid = l + (h-l)/2;
        TreeNode * root = arr[mid];
        root->left = buildTree(arr, l, mid-1);
        root->right = buildTree(arr, mid+1, h);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> arr;
        TreeNode * cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                arr.push_back(cur);
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

        return buildTree(arr, 0, arr.size()-1);

    }
};