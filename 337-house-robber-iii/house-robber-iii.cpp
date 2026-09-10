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
    pair<int,int>dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int>l = dfs(root->left);
        pair<int,int>r = dfs(root->right);
        pair<int,int>curr = {0,0};
        int child = l.first+r.first;
        int grandchild = l.second+r.second;
        curr.first = max(root->val+grandchild,child);
        curr.second = max(curr.second,child);
        return curr;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        pair<int,int>val = dfs(root);
        return val.first;
    }
};