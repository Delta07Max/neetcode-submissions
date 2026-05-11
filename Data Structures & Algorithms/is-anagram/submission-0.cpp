class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if(n!=m)
        {
            return false;
        }

        unordered_map <char, int> count1;
        unordered_map <char, int> count2;
        
        for(int i=0; i<n; i++)
        {
            count1[s[i]]++;
            count2[t[i]]++;
        }

        return count1==count2;
    }
};
