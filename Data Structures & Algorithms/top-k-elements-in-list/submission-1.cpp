class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int>hash;
        vector<int>result;
        int n = nums.size();
        
        vector<vector<int>> freq(n+1);
        for(int i=0; i<n; i++)
        {
            hash[nums[i]]++;
        }

        for(auto it = hash.begin(); it!=hash.end(); ++it)
        {
            freq[it->second].push_back(it->first);
        }

        for(int i = freq.size() - 1; i >= 0; i--)
        {
            int bucketSize = freq[i].size();
            for(int j = 0; j < bucketSize; j++)
            {
                result.push_back(freq[i][j]);
                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};
