class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int>ghodeKiHazamat;

        int left=0, top=0, right=matrix[0].size(), bottom=matrix.size();
        while(left<right && top<bottom)
        {
            for(int i=left; i<right; i++)
            {
                ghodeKiHazamat.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top; i<bottom; i++)
            {
                ghodeKiHazamat.push_back(matrix[i][right-1]);
            }
            right--;

            if (!(left < right && top < bottom))
            {
                break;
            }

            for (int i = right - 1; i >= left; i--)
            {
                ghodeKiHazamat.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            for (int i = bottom - 1; i >= top; i--)
            {
                ghodeKiHazamat.push_back(matrix[i][left]);
            }
            left++;
        }
        return ghodeKiHazamat;
    }
};
