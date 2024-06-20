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
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res(queries.size(), vector<int>(2, -1));

        vector<int> arr;
        TreeNode * cur = root;
        
        while(cur != nullptr){
            if(cur->left == nullptr){
                arr.push_back(cur->val);
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

        for(int i = 0 ; i< queries.size(); i++){
            int l = 0, h = arr.size() - 1;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(queries[i] < arr[mid]){
                    h = mid - 1;
                }
                else if(queries[i] > arr[mid]){
                    l = mid + 1;
                }
                else{
                    res[i][0] = res[i][1] = arr[mid];
                    break;
                }
            }
            if(l>h){
                if(h>=0 && h<arr.size()) res[i][0] = arr[h];
                if(l>=0 && l<arr.size()) res[i][1] = arr[l];
            }
        }
        

        return res;
        
    }
};