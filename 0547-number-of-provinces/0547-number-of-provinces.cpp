class Solution {
public:

    void DFS(vector<vector<int>>& isConnected, vector<bool>& visit, int node){
        visit[node] = true;

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] == 1 && !visit[i]){
                DFS(isConnected, visit, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n, false);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visit[i]){
                count++;
                DFS(isConnected, visit, i);
            }
        }

        return count;
    }
};