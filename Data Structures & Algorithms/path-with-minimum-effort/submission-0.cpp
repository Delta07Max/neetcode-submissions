class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minHeap;

        distance[0][0] = 0;
        minHeap.push({0,0,0});

        vector<vector<int>>dir{{0,1}, {1,0}, {-1,0}, {0,-1}};

        while(!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();
            int diff = curr[0], r = curr[1], c = curr[2];

            if(r == n-1 && c == m-1)
            {
                return diff;
            }

            if(distance[r][c] < diff)
            {
                continue;
            }

            for(auto& d : dir)
            {
                int nr = r+d[0], nc = c+d[1];

                if(nr<0 || nc<0 || nr>=n || nc>=m)
                {
                    continue;
                }

                int newDiff = max(diff, abs(heights[r][c] - heights[nr][nc]));
                if(newDiff < distance[nr][nc])
                {
                    distance[nr][nc] = newDiff;
                    minHeap.push({newDiff,nr,nc});
                }
            }
        }
        return 0;
    }
};