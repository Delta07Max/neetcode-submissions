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
    vector<int>output;
    vector<int> preorderTraversal(TreeNode* root)
    {
        inorder(root);
        return output;
    }

    void inorder(TreeNode* root)
    {
        if(root)
        {
            output.push_back(root->val);
            inorder(root->left);
            inorder(root->right);
        }
    }
};