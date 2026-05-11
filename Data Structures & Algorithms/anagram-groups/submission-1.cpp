class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>>hash;
        int n = strs.size();
        for(int i=0; i<n; i++)
        {
            vector<int> freq(26,0);
            for(int j=0; j<strs[i].length(); j++)
            {
                freq[strs[i][j]-'a']++;
            }

            string key = to_string(freq[0]);

            for(int j=1; j<26; j++)
            {
                key = key + ',' + to_string(freq[j]);
            }

            hash[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& pair : hash)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
