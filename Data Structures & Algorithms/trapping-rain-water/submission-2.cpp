class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        int result=0;
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        int max=0;
        for(int i=0; i<n; i++)
        {
            if(height[i] > max)
            {
                max = height[i];
            }
            leftmax[i] = max;
        }
        max=0;
        for(int i=n-1; i>=0; i--)
        {
            if(height[i] > max)
            {
                max = height[i];
            }
            rightmax[i] = max;
        }

        for(int i=0; i<n; i++)
        {
            result += min(leftmax[i], rightmax[i]) - height[i];
        }
        return result;
    }
};
