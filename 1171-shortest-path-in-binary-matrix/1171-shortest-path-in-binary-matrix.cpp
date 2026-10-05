class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        int src[] = {0, 0};
        int dest[] = {r - 1, c - 1};

        // 0 = open, 1 = blocked
        if (grid[src[0]][src[1]] == 1 ||
            grid[dest[0]][dest[1]] == 1)
            return -1;

        vector<vector<int>> dist(r, vector<int>(c, 1e9));

        queue<pair<int, pair<int, int>>> q;

        dist[src[0]][src[1]] = 1;
        q.push({1, {src[0], src[1]}});

        // 8 directions
        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == dest[0] && col == dest[1])
                return dis;

            for (int i = 0; i < 8; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < r &&
                    ncol >= 0 && ncol < c &&
                    grid[nrow][ncol] == 0 &&
                    dis + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dis + 1;

                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};