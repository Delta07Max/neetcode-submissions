class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int>temp(26,0);
        priority_queue<pair<int,char>> maxHeap;
        queue<tuple<char, int, int>> q;
        int time=0;
        int m = tasks.size();

        for(int i=0; i<m; i++)
        {
            temp[tasks[i]- 'A']++;
        }

        for(int i=0; i<26; i++)
        {
            if(temp[i] > 0)
            {
                maxHeap.push({temp[i], i+'A'});
            }
        }

        while(maxHeap.size() > 0 || q.size()>0)
        {
            int freq=0;
            char task;
            if(maxHeap.size() > 0)
            {
                freq = maxHeap.top().first;
                task = maxHeap.top().second;
                freq--;
                maxHeap.pop();
            }
            time++;
            
            if(freq>0)
            {
                q.push({task,freq,time+n});
            }

            if(q.size() > 0 && get<2>(q.front())==time)
            {
                int queueFreq = get<1>(q.front());
                char queueTask = get<0>(q.front());
                maxHeap.push({queueFreq, queueTask});
                q.pop();
            }
        }
        return time;
    }
};
