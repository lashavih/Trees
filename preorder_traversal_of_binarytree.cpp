/*
Problem Link : "https://www.interviewbit.com/problems/preorder-traversal/".

Solution:
Preorder traversal means printing value of root node, traversing to its left and then to its right.
Stack will serve our purpose just fine.

Note:- Recursion is not allowed.

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack< TreeNode* >st;
    st.push(A);
    struct TreeNode* temp;
    vector<int>vec;
    while(!st.empty()) {
        temp=st.top();
        st.pop();
        vec.push_back(temp->val);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
    //reverse(vec.begin(),vec.end());
    return vec;
}

