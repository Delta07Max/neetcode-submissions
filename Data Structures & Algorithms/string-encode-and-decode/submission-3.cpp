class Solution {
public:

    string encode(vector<string>& strs)
    {
        string s;
        for(int i=0; i<strs.size(); i++)
        {
            s += strs[i];
            s += ".";
        }
        return s;
    }

    vector<string> decode(string s)
    {
        vector<string>str;
        int n=s.length();
        string temp;
        for(int i=0; i<n; i++)
        {
            if(s[i]!='.')
            {
                temp += s[i];
            }
            else
            {
                str.push_back(temp);
                temp.clear();
            }
        }
        return str;
    }
};
