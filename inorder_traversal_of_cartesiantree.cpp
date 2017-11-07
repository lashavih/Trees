/*
Problem link : "https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/".

Solution:
    Since the root is greater than all element in the subtree we can always obtain max
    element in the array and assign max of left to its left node & max of right to its
    right node. Refer to code for better understanding.
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

TreeNode* findtree(vector<int> &A,int l,int r) {
    if(l>r) return NULL;
    int idx=l,ans=A[l];
    for(int i=l;i<=r;i++) {
        if(A[i]>ans) ans=A[i],idx=i;
    }
    struct TreeNode* root=new TreeNode(A[idx]);
    root->left=findtree(A,l,idx-1);
    root->right=findtree(A,idx+1,r);
    return root;
}


TreeNode* Solution::buildTree(vector<int> &A) {
    return findtree(A,0,A.size()-1);
}
