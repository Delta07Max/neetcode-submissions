class Solution {
public:
    int n,m;
    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == false)
                {
                    count++;
                    recurse(i,j,grid,visited);
                }
            }
        }
        return count;
    }

    void recurse(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] == '0' || visited[i][j] == true)
        {
            return;
        }

        visited[i][j] = true;

        recurse(i+1, j, board, visited);
        recurse(i, j+1, board, visited);
        recurse(i-1, j, board, visited);
        recurse(i, j-1, board, visited);
    }
};
