class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        minHeap.push({0,0});
        minDist[0] = 0;

        int result=0;
        
        while(!minHeap.empty())
        {
            auto [cost, u] = minHeap.top();
            minHeap.pop();

            if(inMST[u])
            {
                continue;
            }

            inMST[u] = true;
            result += cost;

            for(int v=0; v<n; v++)
            {
                if(!inMST[v])
                {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    if(dist < minDist[v])
                    {
                        minDist[v] = dist;
                        minHeap.push({dist,v});
                    }
                }
            }
        }
        return result;
    }
};
