class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool>visited(n,false);
        return dfs(0, nums, visited);
    }

    bool dfs(int index, vector<int>& nums, vector<bool>& visited)
    {
        int n = nums.size();
        if(index > n-1 || index < 0)
        {
            return false;
        }
        if(visited[index] == true)
        {
            return false;
        }
        visited[index] = true;
        if(index == n-1)
        {
            return true;
        }
        bool result=false;
        for(int i=1; i<=nums[index]; i++)
        {
            result = result || dfs(index+i,nums,visited);
        }
        return result;
    }
};
