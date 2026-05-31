class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if((i==0 || i==n-1) && board[i][j]=='O')
                {
                    dfs(board,i,j,n,m);
                }
                if((j==0 || j==m-1) && board[i][j]=='O')
                {
                    dfs(board,i,j,n,m);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'O')
        {
            return;
        }

        board[i][j] = '#';

        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j+1,n,m);
        dfs(board,i,j-1,n,m);
    }
};
