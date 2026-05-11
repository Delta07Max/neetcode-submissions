class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left=0, right = heights.size()-1;
        int water=0;
        while(left<right)
        {
            int height=min(heights[left], heights[right]);
            water = max(water,height*(right-left));
            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return water;
    }
};
