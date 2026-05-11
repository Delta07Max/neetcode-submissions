class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int left=1, right = *max_element(piles.begin(), piles.end());
        int result=right, n=piles.size();
        while(left<=right)
        {
            int mid = (left+right)/2;

            long long time = 0;
            for (int i=0; i<n; i++)
            {
                time += ceil(static_cast<double>(piles[i]) / mid);
            }
            if (time <= h)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }
};
