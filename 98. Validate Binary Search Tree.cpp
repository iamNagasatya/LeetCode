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
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;

        TreeNode * cur = root;
        
        while(cur != nullptr){
            if(cur->left == nullptr){
                if(prev >= cur->val) return false;
                prev = cur->val;
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
        return true;
    }
};