class Solution {
public:
vector<string> answer;
vector<string> mappedChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
        {
            return {};
        }

        string curr="";
        backtrack(curr,digits,0);
        return answer;
    }

    void backtrack(string curr, string& digits, int idx)
    {
        if(curr.size() == digits.size())
        {
            answer.push_back(curr);
            return;
        }

        string chars = mappedChar[digits[idx] - '0'];

        for(char ch : chars)
        {
            backtrack(curr+ch, digits, idx+1);
        }
    }
};
