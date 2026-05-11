class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int>hash(nums.begin(), nums.end());
        int n = nums.size();
        int length=0, maxLength=0;
        for(int i=0; i<n; i++)
        {
            if(hash.find(nums[i]-1) == hash.end())
            {
                length=1;
                
                while(hash.count(nums[i]+length))
                {
                    length++;
                }
                maxLength = max(length, maxLength);
            }
        }
        return maxLength;
    }
};
