class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int>maxHeap;
        int n = stones.size();
        for(int i=0; i<n; i++)
        {
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() > 0)
        {
            if(maxHeap.size()==1)
            {
                return maxHeap.top();
            }

            if(maxHeap.size()==2)
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                return temp - maxHeap.top();
            }

            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(a-b!=0)
            {
                maxHeap.push(a-b);
            }
        }
        return 0;
    }
};
