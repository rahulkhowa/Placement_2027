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
    int ans=0;
    set<TreeNode*>st;
    void dfs(TreeNode* root,TreeNode* par){
         if(!root) return;
         dfs(root->left,root);
         dfs(root->right,root);
         if((par==nullptr && !st.contains(root))||(!st.contains(root->left))||(!st.contains(root->right))){
            ans++;
            st.insert(root);
            st.insert(par);
            st.insert(root->left);
            st.insert(root->right);
         }
    }
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        st.insert(nullptr);
        dfs(root,nullptr);
        return ans;
    }
};