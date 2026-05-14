class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int left=0, right=nums.size()-1;
        vector<int>result;
        while(left<=right)
        {
            if(nums[left] + nums[right] == target)
            {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            else if(nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return result;
    }
};
