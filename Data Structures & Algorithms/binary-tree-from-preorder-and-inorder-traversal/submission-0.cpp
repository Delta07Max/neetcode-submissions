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
    unordered_map<int, int>hash;
    int index=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n=inorder.size();
        for(int i=0; i<n; i++)
        {
            hash[inorder[i]]=i;
        }
        return dfs(preorder,0,n-1);
    }

    TreeNode* dfs(vector<int>preorder, int left, int right)
    {
        if(left > right)
        {
            return NULL;
        }

        int rootValue = preorder[index++];
        TreeNode* root = new TreeNode(rootValue);
        int mid = hash[rootValue];

        root->left = dfs(preorder, left, mid-1);
        root->right = dfs(preorder, mid+1, right);
        return root;
    }
};
