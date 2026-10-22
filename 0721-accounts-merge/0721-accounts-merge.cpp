class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> emailToAccount;

        // Step 1: Connect accounts using common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.find(email) ==
                    emailToAccount.end()) {
                    emailToAccount[email] = i;
                }
                else {
                    ds.unionByRank(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group emails by their DSU parent
        vector<vector<string>> mergedEmails(n);

        for (auto &it : emailToAccount) {
            string email = it.first;
            int account = ds.findUPar(it.second);

            mergedEmails[account].push_back(email);
        }

        // Step 3: Build the final answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty())
                continue;

            sort(mergedEmails[i].begin(),
                 mergedEmails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string &email : mergedEmails[i]) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};