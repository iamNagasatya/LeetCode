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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode * , unsigned long long int>> Q;
        Q.push({root, 1});
        unsigned long long ans = 0;
        while(!Q.empty()){
            unsigned long long int n = Q.size();
            unsigned long long a, b;
            for(int i=0; i<n; i++){
                auto p = Q.front();
                Q.pop();

                if(p.first->left) Q.push({p.first->left, 2*(p.second)-1});
                if(p.first->right) Q.push({p.first->right, 2*(p.second)});

                if(i==0){
                    a = p.second;
                }
                if(i==n-1){
                    b = p.second;
                }
            }
            ans = max(ans, b - a + 1);
        }
        return ans;
    }
};