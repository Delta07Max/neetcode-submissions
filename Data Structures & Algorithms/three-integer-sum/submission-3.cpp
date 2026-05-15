class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<vector<int>> results;
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]--;
            for (int j = i + 1; j < n; j++)
            {
                if (mp[nums[j]] <= 0)
                {
                    continue;
                }
                mp[nums[j]]--;
                int target = -(nums[i] + nums[j]);

                if (mp.count(target) && mp[target] > 0)
                {
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        for (auto& vec : st)
        {
            results.push_back(vec);
        }
        return results;
    }
};
