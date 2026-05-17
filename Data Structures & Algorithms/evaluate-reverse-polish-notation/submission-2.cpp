class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int>st;
        int n = tokens.size();
        int a, b;
        for(int i=0; i<n; i++)
        {
            if(tokens[i] == "+")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a+b);
            }
            else if(tokens[i] == "-")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if(tokens[i] == "*")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a*b);
            }
            else if(tokens[i] == "/")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b/a);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
