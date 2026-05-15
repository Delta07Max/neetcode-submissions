class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n=s.length();
        int count=0, ans=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(mp[s[i]]==0)
            {
                mp[s[i]]++;
                count++;
            }
            else
            {
                ans = max(ans,count);
                mp.clear();
                i = i-count;
                count=0;
            }
        }
        return max(ans,count);
    }
};
