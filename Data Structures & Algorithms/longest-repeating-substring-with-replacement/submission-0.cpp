class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n=s.length(), maxFreq=0, ans=0;
        /*for(int i=0; i<n; i++)
        {
            unordered_map<char, int>mp;
            for(int j=i; j<n; j++)
            {
                mp[s[j]]++;
                maxFreq = max(maxFreq, mp[s[j]]);
                int length = j-i+1;
                if(length-maxFreq <= k)
                {
                    ans = max(ans, length);
                }
            }
        }*/

        int left=0, right=0;
        unordered_map<char, int>mp;
        while(right<n)
        {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            int length = right - left + 1;
            while(length - maxFreq > k)
            {
                mp[s[left]]--;
                left++;
                length = right - left + 1;
            }
            ans = max(ans, length);
            right++;
        }
        return ans;
    }
};
