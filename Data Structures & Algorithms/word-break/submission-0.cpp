class Solution {
public:
    unordered_map<int,bool>dp;
    bool wordBreak(string s, vector<string>& wordDict)
    {
        dp[s.length()] = true;
        return dfs(s,wordDict,0);
    }

    bool dfs(string &s, vector<string>& wordDict, int i)
    {
        if(dp.find(i) != dp.end())
        {
            return dp[i];
        }

        for(const string& w : wordDict)
        {
            if(i+w.length() <= s.length() && s.substr(i,w.length())==w)
            {
                if(dfs(s,wordDict,i+w.length()))
                {
                    dp[i] = true;
                    return true;
                }
            }
        }
        dp[i] = false;
        return false;
    }
};
