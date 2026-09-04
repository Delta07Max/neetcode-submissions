class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.length() < t.length())
        {
            return "";
        }

        string result = "";
        vector<int>calcLength(2);
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        int left=0, right=0, n=s.length(), formed=0, size=0;
        for(int i=0; i<t.length(); i++)
        {
            mp1[t[i]]++;
        }

        size = mp1.size();
        int length = INT_MAX;
        while(right < n)
        {
            mp2[s[right]]++;
            if(mp1.count(s[right]) && mp1[s[right]] == mp2[s[right]])
            {
                formed++;
            }

            while(formed == size)
            {
                if(length > right-left+1)
                {
                    length = right-left+1;
                    calcLength[0] = left;
                    calcLength[1] = right;
                }

                mp2[s[left]]--;
                if(mp1.count(s[left]) && mp2[s[left]] < mp1[s[left]])
                {
                    formed--;
                }
                left++;
            }
            right++;
        }

        if(length == INT_MAX)
        {
            return "";
        }

        for(int i=calcLength[0]; i<=calcLength[1]; i++)
        {
            result += s[i];
        }

        return result;
    }
};
