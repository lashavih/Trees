/*
Problem Link : "https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/".
Solution:
    Suppose root is at position x in vertical ordering , then its left child will be at position x-1
    and right child will be at the position x+1.So we keep a map which maps the position x to number
    of nodes at position x in vertical ordering. We will use bfs for traversal in tree.


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

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector< vector<int> >ans;
    if(A==NULL) return ans;
    map< int,vector<int> >mp;
    int dist=0;
    queue< pair<TreeNode*,int> >q;
    q.push(make_pair(A,0));
    while(!q.empty()) {
        pair< TreeNode*,int >temp=q.front();
        q.pop();
        dist=temp.second;
        TreeNode* node=temp.first;
        mp[dist].push_back(node->val);
        if(node->left!=NULL) q.push(make_pair(node->left,dist-1));
        if(node->right!=NULL) q.push(make_pair(node->right,dist+1));
    }

    for(auto it=mp.begin();it!=mp.end();it++) {
        vector<int>vv=it->second;
        ans.push_back(vv);
    }
    return ans;
}
