class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int maxi = nums[0], mini = nums[0];
        int result = nums[0], n=nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i] < 0)
            {
                int temp = maxi;
                maxi = mini;
                mini = temp;
            }

            maxi = max(maxi*nums[i], nums[i]);
            mini = min(mini*nums[i], nums[i]);
            result = max(result, maxi);
        }
        return result;
    }
};