class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    if(n==1)
    return {0};

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int>q;

        for(int i=0;i<degree.size();i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
      int remaining = n;

        while (remaining > 2) {
       int size = q.size();
         remaining -= size;

    for (int i = 0; i < size; i++) {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node]) {
            degree[neighbour]--;

            if (degree[neighbour] == 1) {
                q.push(neighbour);
            }
        }
    }
}

vector<int> ans;

while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
}

return ans;

        
    }
};