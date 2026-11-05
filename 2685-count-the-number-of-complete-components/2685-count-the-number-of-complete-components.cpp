class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(visited[i] == 0) {

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                int nodes = 0;
                int degree = 0;

                while(!q.empty()) {

                    int node = q.front();
                    q.pop();

                    nodes++;
                    degree += adj[node].size();

                    for(auto neigh : adj[node]) {
                        if(visited[neigh] == 0) {
                            visited[neigh] = 1;
                            q.push(neigh);
                        }
                    }
                }

                if(degree == nodes * (nodes - 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};