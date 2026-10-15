
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        time[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) {
                return t;
            }

            for (int i = 0; i < 4; i++) {
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < m) {

                    int newtime = max(t, grid[newr][newc]);

                    if (newtime < time[newr][newc]) {
                        time[newr][newc] = newtime;
                        pq.push({newtime, {newr, newc}});
                    }
                }
            }
        }

        return time[n - 1][m - 1];
    }
};
