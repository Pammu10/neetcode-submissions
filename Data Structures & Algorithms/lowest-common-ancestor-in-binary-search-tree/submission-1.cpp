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
    TreeNode* solve(TreeNode* root, int p, int q){
        if (root->val > p && root->val < q){
            return root;
        }
        if (root->val == p || root->val == q) return root;
        else if (root->val > p && root->val > q) {
            return solve(root->left, p, q);
        }
        else return solve(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        if (pval > qval) return solve(root, qval, pval);
        return solve(root, pval, qval);
    }
};
