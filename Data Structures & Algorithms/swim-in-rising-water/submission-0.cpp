class Solution {
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>minHeap;
        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        vector<vector<int>>dir{{0,1}, {1,0}, {-1,0}, {0,-1}};

        minHeap.push({grid[0][0],0,0});
        distance[0][0] = grid[0][0];

        while(!minHeap.empty())
        {
            auto [dist,r,c] = minHeap.top();
            minHeap.pop();

            if(r == n-1 && c == m-1)
            {
                return dist;
            }

            if(distance[r][c] < dist)
            {
                continue;
            }

            for(auto& d : dir)
            {
                int nr = r+d[0], nc = c+d[1];

                if(nr<0 || nr>=n || nc<0 || nc>=m)
                {
                    continue;
                }

                int newDist = max(dist,grid[nr][nc]);
                if(newDist < distance[nr][nc])
                {
                    distance[nr][nc] = newDist;
                    minHeap.push({newDist, nr, nc});
                }
            }
        }
        return 0;
    }
};
