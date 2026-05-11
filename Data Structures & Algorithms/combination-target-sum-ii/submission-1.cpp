class Solution {
public:
    vector<vector<int>>result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        result.clear();
        sort(candidates.begin(), candidates.end());
        vector<int>current;
        backtracking(candidates, target, current, 0, 0);
        return result;
    }
    void backtracking(vector<int>&candidates, int target, vector<int>current, int i, int total)
    {
        if(total == target)
        {
            result.push_back(current);
            return;
        }

        if(target<0 || i>=candidates.size())
        {
            return;
        }

        current.push_back(candidates[i]);
        backtracking(candidates, target, current, i+1, total+candidates[i]);
        current.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        {
            i++;
        }
        backtracking(candidates, target, current, i+1, total);
    }
};
