class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>adjList;
    vector<string>ans;

    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        for(auto &ticket : tickets)
        {
            adjList[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string src)
    {
        while(!adjList[src].empty())
        {
            string next = adjList[src].top();
            adjList[src].pop();

            dfs(next);
        }
        ans.push_back(src);
    }
};