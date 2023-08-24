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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v2;

        if(solve(root,v1,p->val) and solve(root,v2,q->val)){
            int i=0;
            while(i<v1.size() and i<v2.size()){
                if(v1[i]->val!=v2[i]->val) break;

                i++;
            }
            return v1[i-1];
        }

        return root;
    }
};