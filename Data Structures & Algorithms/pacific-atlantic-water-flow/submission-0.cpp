class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        vector<vector<int>>result;
        for(int i=0; i<n; i++)
        {
            if(pacific[i][0] == false)
            {
                dfs(heights[i][0], heights, pacific, i, 0, n, m);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(atlantic[i][m-1] == false)
            {
                dfs(heights[i][m-1], heights, atlantic, i, m-1, n, m);
            }
        }

        for(int j=0; j<m; j++)
        {
            if(pacific[0][j] == false)
            {
                dfs(heights[0][j], heights, pacific, 0, j, n, m);
            }
        }

        for(int j=0; j<m; j++)
        {
            if(atlantic[n-1][j] == false)
            {
                dfs(heights[n-1][j], heights, atlantic, n-1, j, n, m);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                {
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }

    void dfs(int prev, vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]==true || heights[i][j] < prev)
        {
            return;
        }

        visited[i][j] = true;

        dfs(heights[i][j], heights, visited, i+1, j, n, m);
        dfs(heights[i][j], heights, visited, i-1, j, n, m);
        dfs(heights[i][j], heights, visited, i, j+1, n, m);
        dfs(heights[i][j], heights, visited, i, j-1, n, m);
    }
};
