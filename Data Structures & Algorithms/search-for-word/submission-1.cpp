class Solution {
public:
    int n,m;
    vector<vector<bool>>visited;
    bool exist(vector<vector<char>>& board, string word)
    {
        n=board.size();
        m=board[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        if(index==word.length())
        {
            return true;
        }

        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[index] || visited[i][j])
        {
            return false;
        }

        visited[i][j]=true;

        bool result = dfs(board, word, i+1, j, index+1) || 
                    dfs(board, word, i-1, j, index+1) ||
                    dfs(board, word, i, j-1, index+1) ||
                    dfs(board, word, i, j+1, index+1);

        visited[i][j]=false;

        return result;
    }
};
