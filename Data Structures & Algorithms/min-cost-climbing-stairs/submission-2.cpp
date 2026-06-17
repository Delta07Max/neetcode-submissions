class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int>dp(cost.size(),-1);
        return min(dfs(0,dp,cost),dfs(1,dp,cost));
    }

    int dfs(int i, vector<int>& dp, vector<int>& cost)
    {
        if(i>=cost.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        dp[i] = cost[i] + min(dfs(i+1,dp,cost), dfs(i+2,dp,cost));
        return dp[i];
    }
};
