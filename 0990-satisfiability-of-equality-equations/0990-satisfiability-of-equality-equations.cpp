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
    bool equationsPossible(vector<string>& equations) {

         DisjointSet ds(26);

           for (auto &eq : equations) {
            if (eq[1] == '=') {
                ds.unionByRank(eq[0] - 'a', eq[3] - 'a');
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                if (ds.findUPar(eq[0] - 'a') ==
                    ds.findUPar(eq[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
        
    }
};