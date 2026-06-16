class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        if(target == "0000")
        {
            return 0;
        }
        unordered_set<string>st(deadends.begin(), deadends.end());
        if(st.count("0000"))
        {
            return -1;
        }
        unordered_set<string> visited;
        queue<string> q;
        visited.insert("0000");
        q.push("0000");
        int out=0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                string curr = q.front();
                q.pop();

                if(curr == target)
                {
                    return out;
                }

                for(int i=0; i<4; i++)
                {
                    string up = curr;
                    string down  = curr;

                    up[i] = (curr[i] == '9') ? '0' : curr[i]+1;
                    down[i] = (curr[i] == '0') ? '9' : curr[i]-1;

                    if(!st.count(up) && !visited.count(up))
                    {
                        visited.insert(up);
                        q.push(up);
                    }
                    if(!st.count(down) && !visited.count(down))
                    {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            out++;
        }
        return -1;
    }
};