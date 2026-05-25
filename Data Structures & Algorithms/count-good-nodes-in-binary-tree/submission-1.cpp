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
    int goodNodes(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxVal)
    {
        if(root==NULL)
        {
            return 0;
        }
        int result=0;
        if(root->val >= maxVal)
        {
            result=1;
        }

        int left = dfs(root->left, max(maxVal, root->val));
        int right = dfs(root->right, max(maxVal, root->val));
        return result+left+right;
    }
};
