class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> hash;
        int n = s.length();
        int count=0, maxCount=0;
        for(int i=0; i<n; i++)
        {
            int c = s[i]-'a';
            if(hash.count(c)==0)
            {
                hash[c]++;
                count++;
            }
            else
            {
                maxCount = max(maxCount,count);
                i=i-count;
                hash.clear();
                count=0;
            }
        }
        maxCount = max(maxCount,count);
        return maxCount;
    }
};
