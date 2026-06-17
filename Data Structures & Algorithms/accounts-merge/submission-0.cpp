class DSU {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb) {
            parent[pb] = pa;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        DSU dsu;
        unordered_map<string, string> emailToName;

        for (auto &acc : accounts)
        {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++)
            {
                string email = acc[i];
                if (!dsu.parent.count(email))
                {
                    dsu.parent[email] = email;
                }
                emailToName[email] = name;
            }
        }

        for (auto &acc : accounts)
        {
            string firstEmail = acc[1];
            for (int i = 2; i < acc.size(); i++)
            {
                dsu.unite(firstEmail, acc[i]);
            }
        }

        unordered_map<string, vector<string>> groups;

        for (auto &p : dsu.parent)
        {
            string email = p.first;
            string root = dsu.find(email);
            groups[root].push_back(email);
        }

        vector<vector<string>> res;

        for (auto &g : groups)
        {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());

            string name = emailToName[g.first];
            emails.insert(emails.begin(), name);

            res.push_back(emails);
        }
        return res;
    }
};