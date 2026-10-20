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
        if (parent[node] == node) {
            return node;
        }

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        DisjointSet ds(n);

        int count = n;  // Connected components
        int c = 0;      // Extra cables

        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {
                c++;
            }
            else {
                ds.unionByRank(u, v);
                count--;
            }
        }

        if (c >= count - 1) {
            return count - 1;
        }

        return -1;
    }
};