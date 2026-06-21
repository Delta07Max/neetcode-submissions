class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int>mp;

        while(n!=1 || mp.count(n))
        {
            if(mp.count(n))
            {
                return false;
            }

            mp.insert(n);
            n=sq(n);
        }
        return true;
    }

    int sq(int num)
    {
        int ans=0;
        while(num>0)
        {
            ans += (num%10)*(num%10);
            num /= 10;
        }
        return ans;
    }
};
