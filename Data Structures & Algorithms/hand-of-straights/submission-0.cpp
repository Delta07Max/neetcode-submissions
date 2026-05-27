class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        int n = hand.size();
        if(n % groupSize != 0)
        {
            return false;
        }
        unordered_map<int,int>mp;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(int i=0; i<n; i++)
        {
            mp[hand[i]]++;
            if(mp[hand[i]] == 1)
            {
                minHeap.push(hand[i]);
            }
        }

        while(!minHeap.empty())
        {
            while(!minHeap.empty() && mp[minHeap.top()] == 0)
            {
                minHeap.pop();
            }

            if(minHeap.empty())
            {
                break;
            }

            int idx = minHeap.top();
            for(int i=idx; i<idx+groupSize; i++)
            {
                if(mp[i]<1)
                {
                    return false;
                }
                else
                {
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
