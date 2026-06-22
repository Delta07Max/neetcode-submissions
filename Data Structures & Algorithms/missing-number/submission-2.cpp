class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int ghoda = n;
        for(int i=0; i<n; i++)
        {
            ghoda ^= i^nums[i];
        }
        return ghoda;
    }
};
