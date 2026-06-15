class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        queue<pair<int,int>>q;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(auto &[dr,dc] : direction)
            {
                int nr = r+dr;
                int nc = c+dc;

                if(nr<0 || nr>=n || nc<0 || nc>=m)
                {
                    continue;
                }

                if(grid[nr][nc]!= INT_MAX)
                {
                    continue;
                }

                grid[nr][nc] = grid[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
};
