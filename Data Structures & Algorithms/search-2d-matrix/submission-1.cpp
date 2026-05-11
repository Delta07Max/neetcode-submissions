class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int up=0, down=rows-1;
        int left=0, right=cols-1;

        while(up<=down)
        {
            int mid1 = (up+down)/2;
            
            if(matrix[mid1][cols-1] < target)
            {
                up = mid1+1;
            }
            else if(matrix[mid1][0] > target)
            {
                down = mid1-1;
            }
            else
            {
                break;
            }
        }

        if(!(up <= down))
        {
            return false;
        }

        int mid1 = (up+down)/2;
        while(left<=right)
        {
            int mid2 = (left+right)/2;

            if(target > matrix[mid1][mid2])
            {
                left = mid2+1;
            }
            else if(target < matrix[mid1][mid2])
            {
                right = mid2-1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
