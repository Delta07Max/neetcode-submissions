class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        stack<int>st1;
        stack<int>st2;

        for(int i=n-1; i>=0; i--)
        {
            while(!st1.empty() && heights[st1.top()]>=heights[i])
            {
                st1.pop();
            }

            if(!st1.empty())
            {
                nse[i] = st1.top();
            }
            st1.push(i);
        }

        for(int i=0; i<n; i++)
        {
            while(!st2.empty() && heights[st2.top()] >= heights[i])
            {
                st2.pop();
            }

            if(!st2.empty())
            {
                pse[i] = st2.top();
            }
            st2.push(i);
        }

        int maxi=0;
        for(int i=0; i<n; i++)
        {
            //pse[i]+=1;
            //nse[i]-=1;
            maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};
