class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<int> current;
        backtrack(nums, current, target, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& current, int target, int i)
    {
        if(target==0)
        {
            result.push_back(current);
            return;
        }

        if(target<0 || i>=nums.size())
        {
            return;
        }
        current.push_back(nums[i]);
        backtrack(nums, current, target-nums[i],i);
        current.pop_back();
        backtrack(nums, current, target, i+1);
    }
};
