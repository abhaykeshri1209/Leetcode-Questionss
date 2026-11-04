class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int steps = 1;

        vector<int> visited(n, 0);
        queue<int> q;

        visited[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : rooms[node]) {
                if (visited[it] == 0) {
                    visited[it] = 1;
                    steps++;
                    q.push(it);
                }
            }
        }

        return steps == n;
    }
};