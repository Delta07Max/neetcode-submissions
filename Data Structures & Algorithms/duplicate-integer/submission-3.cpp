class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            hashmap[nums[i]]=0;
        }

        for(int i=0; i<n; i++)
        {
            if(hashmap[nums[i]]==1)
            {
                return true;
            }
            else
            {
                hashmap[nums[i]]++;
            }
        }
        return false;
    }
};