/*
Problem link : "https://www.interviewbit.com/problems/balanced-binary-tree/".

Solution:
    One simple recursion will do the trick.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* node) {
    if(!node) return 0;
    if(!node->left && !node->right) return 1;
    int lh=1+height(node->left);
    int rh=1+height(node->right);
    if(lh<0 || rh<0) return INT_MIN;
    if(abs(lh-rh)>1) return INT_MIN;
    return max(lh,rh);
}

int Solution::isBalanced(TreeNode* A) {
    if(height(A)<0) return 0;
    return 1;
}
