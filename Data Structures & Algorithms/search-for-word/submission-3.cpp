class Solution {
public:
    int n,m;
    bool exist(vector<vector<char>>& board, string word)
    {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>>visited;
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(search(i,j,board,word,0,visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(int i, int j, vector<vector<char>>& board, string word, int idx, vector<vector<bool>>& visited)
    {
        if(idx == word.length())
        {
            return true;
        }

        if(i>=n || j>=m || i<0 || j<0 || board[i][j]!= word[idx] || visited[i][j])
        {
            return false;
        }

        visited[i][j] = true;

        bool final = search(i+1, j, board, word, idx+1, visited) || search(i, j+1, board, word, idx+1, visited) || search(i-1, j, board, word, idx+1, visited) || search(i, j-1, board, word, idx+1, visited);

        visited[i][j] = false;

        return final;
    }
};
