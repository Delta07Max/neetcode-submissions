class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if(nums[0] < nums[n-1])
        {
            return nums[0];
        }

        int left=0, right=n-1;
        while(left < right)
        {
            int mid = (left+right)/2;
            if(nums[right] > nums[mid])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return nums[left];
    }
};
