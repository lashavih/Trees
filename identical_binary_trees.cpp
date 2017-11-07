/*
Problem link : "https://www.interviewbit.com/problems/identical-binary-trees/".
Solution :
    make a queue of pair of TreeNode which contains the current nodes of tree 1
    and 2 respectively and check whether they are equal or not.
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    queue< pair<TreeNode*, TreeNode* > >q;
    q.push(make_pair(A,B));
    struct TreeNode* t1;
    struct TreeNode* t2;
    while(!q.empty()) {
        t1=q.front().first;
        t2=q.front().second;
        q.pop();
        if(t1==NULL || t2==NULL) break;
        if(t1->val !=t2->val) return 0;
        q.push(make_pair(t1->left,t2->left));
        q.push(make_pair(t1->right,t2->right));
    }
    if(t1!=t2) return 0;
    return 1;
}
