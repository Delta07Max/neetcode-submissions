class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days)
    {
        int left = nums[0], right=0, n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(left < nums[i])
            {
                left = nums[i];
            }
            right += nums[i];
        }
        int result=right;
        while(left <= right)
        {
            int mid = (left+right)/2;
            int d = checkCapacity(mid,nums,n);
            if(d <= days)
            {
                right = mid-1;
                result = min(mid,result);
            }
            else
            {
                left = mid+1;
            }
        }
        return result;
    }

    int checkCapacity(int cap, vector<int>& nums, int n)
    {
        int days=1, temp=cap;
        for(int i=0; i<n; i++)
        {
            if(cap < nums[i])
            {
                days++;
                cap = temp;
            }
            cap -= nums[i];
        }
        return days;
    }
};