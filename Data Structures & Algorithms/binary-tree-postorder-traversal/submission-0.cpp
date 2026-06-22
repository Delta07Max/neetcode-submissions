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
    vector<int> postorderTraversal(TreeNode* root)
    {
        postorder(root);
        return output;
    }

    void postorder(TreeNode* root)
    {
        if(root)
        {
            postorder(root->left);
            postorder(root->right);
            output.push_back(root->val);
        }
    }
};