/*
Problem Link : "https://www.interviewbit.com/problems/inorder-traversal/".

Solution:
    If we notice,inorder traversal is nothing but printing traversing through left node until its null
    and then traversing to its right node.Luckily we have a very good data structure "stack" to serve
    this purpose.We are going to create a stack of TreeNode and keep pushing left nodes in it until
    the node is null. Please have a look at code for better understanding.

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack< TreeNode* >st;
    struct TreeNode* root=A;
    vector<int>ans;
    while(1) {
        while(root!=NULL) {
            st.push(root);
            root=root->left;
        }
        if(st.empty()) break;
        root=st.top();
        st.pop();
        ans.push_back(root->val);
        root=root->right;
    }
    return ans;
}
