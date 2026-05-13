class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> result;
        int n = strs.size();
        for(int i=0; i<n; i++)
        {
            string s;
            vector<int>freq(26,0);
            for(int j=0; j<strs[i].length(); j++)
            {
                freq[strs[i][j]-'a']++;
            }

            for(int j=0; j<26; j++)
            {
                s += to_string(freq[j]);
                s += "#";
            }
            mp[s].push_back(strs[i]);
        }

        for(pair<string, vector<string>> x : mp)
        {
            result.push_back(x.second);
        }

        return result;
    }
};
