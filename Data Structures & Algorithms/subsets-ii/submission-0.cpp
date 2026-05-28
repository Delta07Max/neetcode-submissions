class Solution {
    set<vector<int>>final;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> current;
        subsets(0,nums,current);
        return vector<vector<int>>(final.begin(), final.end());
    }

    void subsets(int idx, vector<int>& nums, vector<int>& current)
    {
        if(idx == nums.size())
        {
            final.insert(current);
            return;
        }

        current.push_back(nums[idx]);
        subsets(idx+1,nums,current);
        current.pop_back();
        subsets(idx+1,nums,current);
    }
};
