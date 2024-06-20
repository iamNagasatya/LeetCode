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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int prev = INT_MIN, cnt = 0, max_cnt = 0;
        TreeNode * cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                if(prev == cur->val) cnt++;
                else{
                    if(cnt == max_cnt){
                        res.push_back(prev);
                    }
                    else if(cnt > max_cnt){
                        res.clear();
                        res.push_back(prev);
                        max_cnt = cnt;
                    }

                    prev = cur->val;
                    cnt = 1;
                }
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
        
        if(cnt == max_cnt){
            res.push_back(prev);
        }
        else if(cnt > max_cnt){
            res.clear();
            res.push_back(prev);
            max_cnt = cnt;
        }

        return res;
    }
};