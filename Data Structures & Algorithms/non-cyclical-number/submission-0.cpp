class Solution {
public:
    int squares(int n)
    {
        int result=0;
        while(n>0)
        {
            result = result + (n%10)*(n%10);
            n=n/10;
        }
        return result;
    }
    bool isHappy(int n)
    {
        unordered_map<int,int>hash;
        while(n!=1 || hash.count(n))
        {
            if(hash.count(n))
            {
                return false;
            }
            hash[n]=1;
            n=squares(n);
        }
        return true;
    }
};
