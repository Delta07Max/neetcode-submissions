class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map <int, int> freq;

        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            if(freq[nums[i]]>1)
            {
                return true;
            }
        }
        return false;
    }
};