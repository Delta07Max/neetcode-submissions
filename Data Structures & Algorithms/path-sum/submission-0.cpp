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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        return dfs(root,targetSum);
    }

    bool dfs(TreeNode* root, int rSum)
    {
        if(root==NULL)
        {
            return false;
        }
        rSum -= root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(rSum==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return dfs(root->left,rSum) || dfs(root->right,rSum);
    }
};