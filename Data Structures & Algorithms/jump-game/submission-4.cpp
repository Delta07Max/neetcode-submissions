class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        return dfs(0, nums);
    }

    bool dfs(int index, vector<int>& nums)
    {
        if(index == nums.size()-1)
        {
            return true;
        }

        if(index > nums.size())
        {
            return false;
        }

        for(int i=1; i<=nums[index]; i++)
        {
            if(dfs(i+index, nums))
            {
                return true;
            }
        }
        return false;
    }
};
