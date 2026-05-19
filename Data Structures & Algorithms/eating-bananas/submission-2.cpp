class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int right = *max_element(piles.begin(), piles.end());
        int left=1, n=piles.size(), result=right;
        while(left <= right)
        {
            int time=0;
            int mid=(left+right)/2;
            for(int i=0; i<n; i++)
            {
                int temp = piles[i]/mid;
                if(piles[i] > temp*mid)
                {
                    time++;
                }
                time += temp;
            }
            if(time <= h)
            {
                result = min(result, mid);
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return result;
    }
};
