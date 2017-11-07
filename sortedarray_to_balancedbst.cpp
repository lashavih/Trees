/*
Problem link : "https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/".

Solution :
    Since the resultant bst should be balanced, we should divide each segment into
    two parts ,take mid as its root element and do the same for its left and right
    part recursively .

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

TreeNode* build(const vector<int> &A,int l,int r) {
    if(l>r) return NULL;
    int mid=(l+r)/2;
    struct TreeNode* temp=new TreeNode(A[mid]);
    if(l==r) return temp;
    temp->left=build(A,l,mid-1);
    temp->right=build(A,mid+1,r);
    return temp;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n=A.size();
    return build(A,0,n-1);
}
