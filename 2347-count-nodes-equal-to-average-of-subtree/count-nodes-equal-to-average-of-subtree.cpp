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
    int ans=0,sum=0,ct=0;

    void solve1(TreeNode* root){
        if(root!=NULL){
            solve1(root->left);
            sum+=root->val;
            ct+=1;
            solve1(root->right);
        }
    }

    void solve(TreeNode* root){
        if(root!=NULL){
            solve(root->left);
            sum=0;
            ct=0;
            solve1(root);
            if(sum/ct==root->val)ans+=1;
            solve(root->right);
        }
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;      
    }
};