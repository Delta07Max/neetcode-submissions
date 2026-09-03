class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        int maxCount=0;
        for(int i=0; i<n; i++)
        {
            if(!mp.count(nums[i]-1))
            {
                int j=0, count=0;
                while(mp.count(nums[i] + j))
                {
                    count++;
                    mp[nums[i]+j]--;
                    j++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
