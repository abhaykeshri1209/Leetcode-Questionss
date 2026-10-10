
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[entrance[0]][entrance[1]] = 0;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 4; i++) {
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m &&
                    maze[newr][newc] == '.' &&
                    distance[newr][newc] == 1e9) {

                    distance[newr][newc] = steps + 1;

                    if (newr == 0 || newr == n - 1 ||
                        newc == 0 || newc == m - 1) {
                        return steps + 1;
                    }

                    q.push({steps + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};

