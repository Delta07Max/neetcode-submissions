class Solution {
public:
    int n,m;
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0, count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(visited[i][j] == false && grid[i][j]==1)
                {
                    count=0;
                    recurse(i,j,grid,visited,count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }

    void recurse(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& count)
    {
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] == true || grid[i][j] == 0)
        {
            return;
        }

        visited[i][j] = true;
        count++;
        recurse(i+1,j,grid,visited,count);
        recurse(i,j+1,grid,visited,count);
        recurse(i,j-1,grid,visited,count);
        recurse(i-1,j,grid,visited,count);
    }
};
