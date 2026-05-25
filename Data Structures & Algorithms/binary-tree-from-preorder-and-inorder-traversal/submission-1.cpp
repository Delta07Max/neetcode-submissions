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
    int idx=0;
    unordered_map<int, int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = inorder.size();
        for(int i=0; i<n; i++)
        {
            mp[inorder[i]]=i;
        }
        return build(0,n-1,preorder);
    }

    TreeNode* build(int left, int right, vector<int>& preorder)
    {
        if(left > right)
        {
            return NULL;
        }
        int rootValue = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(rootValue);
        int mid = mp[rootValue];
        root->left = build(left, mid-1, preorder);
        root->right = build(mid+1, right, preorder);
        return root;
    }
};
