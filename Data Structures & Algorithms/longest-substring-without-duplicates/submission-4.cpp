class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int>mp;
        int left=0, right=0, n=s.length();
        int length=0, maxlen=0;
        while(right < n)
        {
            if(mp.count(s[right]))
            {
                int idx = mp[s[right]];
                left = max(left,idx+1);
                length = right-left;
            }
            mp[s[right]]=right;
            length++;
            maxlen = max(maxlen, length);
            right++;
        }
        
        return max(maxlen, length);
    }
};
