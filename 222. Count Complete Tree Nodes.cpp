class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode * cur = root;
        
        int lh = 0, rh = 0;
        while(cur){
            lh++;
            cur = cur->left;
        }
        cur = root;
        while(cur){
            rh++;
            cur = cur->right;
        }

        if(lh==rh){
            return (1<<(lh)) - 1; 
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};