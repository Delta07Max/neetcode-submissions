class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<vector<int>> final;
        vector<int> current;
        targetSum(nums,0,target,current,final);
        return final;
    }

    void targetSum(vector<int>& nums, int idx, int target, vector<int>& current, vector<vector<int>>& final)
    {
        if(target == 0)
        {
            final.push_back(current);
            return;
        }
        
        if(target < 0)
        {
            return;
        }

        for(int i=idx; i<nums.size(); i++)
        {
            current.push_back(nums[i]);
            targetSum(nums, i, target-nums[i], current, final);
            current.pop_back();
        }
    }
};
