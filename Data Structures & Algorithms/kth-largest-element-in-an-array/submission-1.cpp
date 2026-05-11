class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(i<k)
            {
                minHeap.push(nums[i]);
            }
            else
            {
                minHeap.push(nums[i]);
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
