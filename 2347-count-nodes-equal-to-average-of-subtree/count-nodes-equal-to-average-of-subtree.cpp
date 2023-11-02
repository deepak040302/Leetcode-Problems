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
    vector<int> solve(TreeNode* root){
        if(root==NULL) return {0,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int sum = left[0] + right[0] + root->val;
        int nct = left[1] + right[1] + 1;

        if(root->val == sum/nct) ans+=1;

        return {sum,nct};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};