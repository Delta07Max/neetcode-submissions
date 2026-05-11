class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashmap;
        vector<int>result;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            hashmap[nums[i]] = i;
        }

        for(int i=0; i<n; i++)
        {
            if(hashmap.count(target - nums[i]) && hashmap[target - nums[i]] != i)
            {
                result.push_back(i);
                result.push_back(hashmap[target - nums[i]]);
                return result;
            }
        }

        return result;
    }
};
