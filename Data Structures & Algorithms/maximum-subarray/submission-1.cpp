class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int currentSum=nums[0];
        int max=currentSum;
        int n=nums.size();
        for(int i=1; i<n; i++)
        {
            if(currentSum + nums[i] < nums[i])
            {
                currentSum = nums[i];
            }
            else
            {
                currentSum += nums[i];
            }
            if(max < currentSum)
            {
                max = currentSum;
            }
        }
        return max;
    }
};
