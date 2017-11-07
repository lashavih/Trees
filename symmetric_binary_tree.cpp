/*
Problem link : "https://www.interviewbit.com/problems/symmetric-binary-tree/".
Solution:
    make a queue of pair of TreeNode which contains the current left node of tree 1
    and right node of tree 2 or vice versa respectively and check whether they are equal or not.
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
int Solution::isSymmetric(TreeNode* A) {
    queue< pair<TreeNode*, TreeNode* > >q;
    struct TreeNode* t1;
    struct TreeNode* t2;
    if(A==NULL) return 1;
    q.push(make_pair(A->left,A->right));
    while(!q.empty()) {
        t1=q.front().first;
        t2=q.front().second;
        q.pop();
        if(t1==NULL && t2==NULL) return 1;
        if(t1==NULL || t2==NULL) return 0;
        if(t1->val!=t2->val) return 0;
        q.push(make_pair(t1->left,t2->right));
        q.push(make_pair(t1->right,t2->left));
    }
    if(t1!=t2) return 0;
    return 1;
}
