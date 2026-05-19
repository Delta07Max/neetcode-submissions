class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int up=0, down=rows-1;

        while(up <= down)
        {
            int mid = (up+down)/2;
            if(matrix[mid][0] <= target && matrix[mid][cols-1] >= target)
            {
                int left=0, right=cols-1;
                while(left <= right)
                {
                    int middle = (left+right)/2;
                    if(matrix[mid][middle] == target)
                    {
                        return true;
                    }
                    else if(matrix[mid][middle] > target)
                    {
                        right = middle-1;
                    }
                    else
                    {
                        left=middle+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0] < target)
            {
                up = mid+1;
            }
            else if(matrix[mid][0] > target)
            {
                down = mid-1;
            }
        }
        return false;
    }
};
