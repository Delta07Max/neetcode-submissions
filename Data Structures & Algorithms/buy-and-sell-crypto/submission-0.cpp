class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int l=0, r=1;
        int n = prices.size(), maxProfit=0;
        while(r<n)
        {
            int profit=0;
            if(prices[l] < prices[r])
            {
                profit = prices[r] - prices[l];
            }
            else
            {
                l=r;
            }
            r++;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};
