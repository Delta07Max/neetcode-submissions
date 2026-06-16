class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if(beginWord == endWord)
        {
            return 0;
        }
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty())
        {
            auto [word,out] = q.front();

            if(word == endWord)
            {
                return out;
            }

            for(int i=0; i<word.size(); i++)
            {
                char curr = word[i];

                for(char ch = 'a'; ch<= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.count(word))
                    {
                        q.push({word,out+1});
                        st.erase(word);
                    }
                }
                word[i] = curr;
            }
            q.pop();
        }
        return 0;
    }
};
