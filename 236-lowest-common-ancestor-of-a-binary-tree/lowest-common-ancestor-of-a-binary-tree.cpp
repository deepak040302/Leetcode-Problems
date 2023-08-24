/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,vector<TreeNode*>&v,int tar){
        v.push_back(root);

        if(root->val==tar) return true;

        if(root->left and solve(root->left,v,tar)) return true;

        if(root->right and solve(root->right,v,tar)) return true;

        v.pop_back();

        return false;
    }


    TreeNode* solve1(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL) return NULL;
        if(root->val == p->val) return root;
        if(root->val == q->val) return root;

        TreeNode* l = solve1(root->left,p,q);
        TreeNode* r = solve1(root->right,p,q);

        if(l==NULL) return r;
        if(r==NULL) return l;

        if(l==NULL and r==NULL) return NULL;

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return solve1(root,p,q);
    }
};