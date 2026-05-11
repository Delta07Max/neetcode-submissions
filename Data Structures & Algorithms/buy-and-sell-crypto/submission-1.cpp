class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int n = prices.size(), minPrice = prices[0];
        for(int i=1; i<n; i++)
        {
            if(minPrice > prices[i])
            {
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            if(profit > max)
            {
                max = profit;
            }
        }
        return max;
    }
};
