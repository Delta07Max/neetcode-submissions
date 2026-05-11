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
        return good(root, root->val);
    }

    int good(TreeNode* node, int maxVal)
    {
        if(!node)
        {
            return 0;
        }

        int result = (node->val >= maxVal) ? 1:0;
        maxVal = max(maxVal, node->val);
        result += good(node->left, maxVal);
        result += good(node->right, maxVal);
        return result;
    }
};
