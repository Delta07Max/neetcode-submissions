class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count=0, maxArea=0;
        vector<vector<int>> visited(n,vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    count=0;
                    dfs(grid, visited, i, j, n, m, count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int n, int m, int& count)
    {
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]==1 || grid[i][j]==0)
        {
            return;
        }
        visited[i][j]=1;
        count++;
        dfs(grid, visited, i+1, j, n, m, count);
        dfs(grid, visited, i-1, j, n, m, count);
        dfs(grid, visited, i, j+1, n, m, count);
        dfs(grid, visited, i, j-1, n, m, count);
    }
};