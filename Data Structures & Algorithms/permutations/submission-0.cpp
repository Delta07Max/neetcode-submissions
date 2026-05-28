class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> current;
        vector<bool> visited(n, false);
        vector<vector<int>> final;
        permutation(visited,nums,current,final);
        return final;
    }

    void permutation(vector<bool>& visited, vector<int>& nums, vector<int>& current, vector<vector<int>>& final)
    {
        if(current.size() == nums.size())
        {
            final.push_back(current);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i] == false)
            {
                current.push_back(nums[i]);
                visited[i] = true;
                permutation(visited,nums,current,final);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};
