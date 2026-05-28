class Solution {
public:
    vector<vector<int>>subsets(vector<int>& nums)
    {
        vector<vector<int>>final;
        vector<int>current;
        makeSubset(0,nums,current,final);
        return final;
    }

    void makeSubset(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& final)
    {
        if(idx == nums.size())
        {
            final.push_back(current);
            return;
        }

        current.push_back(nums[idx]);

        makeSubset(idx+1, nums, current, final);

        current.pop_back();

        makeSubset(idx+1, nums, current, final);
    }
};
