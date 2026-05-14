class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left=0, right=heights.size()-1;
        int maxWater=0;

        while(left<right)
        {
            int height = min(heights[left], heights[right]);
            int water = height*(right - left);

            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            if(maxWater < water)
            {
                maxWater = water;
            }
        }
        return maxWater;
    }
};
