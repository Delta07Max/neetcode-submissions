class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2)
        {
            return false;
        }
        vector<int>smallMap(26, 0);
        vector<int>largeMap(26, 0);
        for(int i=0; i<n1; i++)
        {
            smallMap[s1[i]-'a']++;
            largeMap[s2[i]-'a']++;
        }
        if(smallMap == largeMap)
        {
            return true;
        }
        int start=0;
        for(int i=n1; i<n2; i++)
        {
            largeMap[s2[start]-'a']--;
            largeMap[s2[i]-'a']++;
            if(largeMap == smallMap)
            {
                return true;
            }
            start++;
        }
        return false;
    }
};
