class Solution {
public:
    bool isValid(string s)
    {
        stack<char>bracket;

        for(char c : s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                bracket.push(c);
            }
            else
            {
                if(bracket.empty())
                {
                    return false;
                }
                if(c==')' && bracket.top() != '(')
                {
                    return false;
                }
                if(c=='}' && bracket.top() != '{')
                {
                    return false;
                }
                if(c==']' && bracket.top() != '[')
                {
                    return false;
                }

                bracket.pop();
            }
        }
        
        return bracket.empty();
    }
};
