class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        sort(coins.begin(), coins.end());

        vector<vector<int>>dp(coins.size() + 1,vector<int>(amount + 1, -1));

        return check(0, amount, coins, dp);
    }

    int check(int i, int a, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(a == 0)
        {
            return 1;
        }

        if(i>=coins.size())
        {
            return 0;
        }

        if (dp[i][a] != -1)
        {
            return dp[i][a];
        }

        int res=0;
        if(coins[i] <= a)
        {
            res = check(i+1, a, coins, dp);
            res += check(i, a-coins[i], coins, dp);
        }

        dp[i][a] = res;
        return res;
    }
};
