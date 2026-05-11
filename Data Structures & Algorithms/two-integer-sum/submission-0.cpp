class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int,int>hash;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            hash[nums[i]]=i;
        }

        for(int i=0; i<n; i++)
        {
            int diff = target - nums[i];
            if(hash.count(diff) && hash[diff]!=i)
            {
                return {i, hash[diff]};
            }
        }
    }
};
