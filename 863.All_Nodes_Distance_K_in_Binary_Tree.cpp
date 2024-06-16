/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> res;

    void distk(TreeNode * root, int k){
        if(root){
            if(k==0){
                res.push_back(root->val);
                return;
            }
            distk(root->right, k-1);
            distk(root->left, k-1);
        }
    }

    int findk(TreeNode * root, int target, int k, int d){
        if(root){
            if(root->val == target){
                distk(root, k);
                return d;
            }
            int l = findk(root->left, target, k, d+1);
            if(l!=-1){
                int c = k - (l-d);
                if(c==0){
                    res.push_back(root->val);
                    return -1;
                }
                if(c>0){
                    distk(root->right, c-1);
                    return l;
                }
            }

            int r = findk(root->right, target, k, d+1);
            if(r!=-1){
                int c = k - (r-d);
                if(c==0){
                    res.push_back(root->val);
                    return -1;
                }
                if(c>0){
                    distk(root->left, c-1);
                    return r;
                }
            }
            return -1;

        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findk(root, target->val, k, 0);
        return res;
    }
};