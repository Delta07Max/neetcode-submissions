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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(root == NULL)
        {
            return "";
        }
        
        string answer = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node)
                {
                    answer += to_string(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    answer += '*';
                }
                answer += ',';
            }
        }
        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data.length() == 0)
        {
            return NULL;
        }

        vector<string>tokens;
        int n = data.length();
        string temp="";
        for(int i=0; i<n; i++)
        {
            if(data[i] == ',')
            {
                tokens.push_back(temp);
                temp="";
            }
            else
            {
                temp += data[i];
            }
        }

        if(tokens[0] == "*")
        {
            return NULL;
        }

        queue<TreeNode*>q;
        TreeNode* root = new TreeNode (stoi(tokens[0]));
        q.push(root);
        int idx=1;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(idx < tokens.size())
            {
                if(tokens[idx]!= "*")
                {
                    node->left = new TreeNode (stoi(tokens[idx]));
                    q.push(node->left);
                }
                idx++;
            }

            if(idx < tokens.size())
            {
                if(tokens[idx]!="*")
                {
                    node->right = new TreeNode (stoi(tokens[idx]));
                    q.push(node->right);
                }
                idx++;
            }
        }
        return root;
    }
};
