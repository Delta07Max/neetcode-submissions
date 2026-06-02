class Solution {
public:
    bool isPalindrome(string s)
    {
        string final;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i]!= ' ' && isalnum(s[i]))
            {
                final += s[i];
            }
        }
        n=final.length();
        for(int i=0; i<n; i++)
        {
            if(tolower(final[i]) != tolower(final[n-i-1]))
            {
                return false;
            }
        }
        return true;
    }
};
