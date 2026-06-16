class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int>distance(n+1,INT_MAX);

        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        minHeap.push({0,k});
        distance[k]=0;

        while(!minHeap.empty())
        {
            auto [dist,src] = minHeap.top();
            minHeap.pop();

            if(dist > distance[src])
            {
                continue;
            }

            for(auto &[n,wt] : adj[src])
            {
                if(dist + wt < distance[n])
                {
                    distance[n] = dist+wt;
                    minHeap.push({distance[n],n});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(distance[i] == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};
