class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        if(n!=m)
        {
            return false;
        }
        vector<int>anagram(26,0);

        for(int i=0; i<n; i++)
        {
            anagram[s[i]-'a']++;
            anagram[t[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(anagram[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
