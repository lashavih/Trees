/*
Problem Link : "https://www.interviewbit.com/problems/postorder-traversal/".

Solution:
    As we all know, postorder traversal is nothing but traversing left node, traversing right node
    and printing node value. We are going to do the same by maintaining a stack of Treenode.

Note:- Recursion is not allowed.

/*


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack< TreeNode* >st;
    st.push(A);
    struct TreeNode* temp;
    vector<int>vec;
    while(!st.empty()) {
        temp=st.top();
        st.pop();
        vec.push_back(temp->val);
        if(temp->left!=NULL) st.push(temp->left);
        if(temp->right!=NULL) st.push(temp->right);
    }
    reverse(vec.begin(),vec.end());
    return vec;
}

