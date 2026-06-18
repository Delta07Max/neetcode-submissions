class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>prefixSum(n+1,0);
        for(int i=0; i<n; i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int result=1;
        for(int i=0; i<n; i++)
        {
            int left=0, right=i;
            while(left<=right)
            {
                int m = (left+right)/2;
                long long curSum = prefixSum[i+1] - prefixSum[m];
                long long need = (i - m + 1) * 1LL * nums[i] - curSum;
                if (need <= k)
                {
                    right = m - 1;
                    result = max(result, i - m + 1);
                }
                else
                {
                    left = m + 1;
                }
            }
        }
        return result;
    }
};