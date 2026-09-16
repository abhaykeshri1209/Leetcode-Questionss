class Solution {
public:

private:
    bool dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int delrow[], int delcol[]) {

        // mark current cell visited
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        bool closed = true;

        // current cell touches boundary
        if(row == 0 || row == n-1 || col == 0 || col == m-1) {
            closed = false;
        }

        // check 4 directions
        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               grid[nrow][ncol] == 0) {

                // if connected cell is not closed
                if(!dfs(nrow, ncol, vis, grid, delrow, delcol)) {
                    closed = false;
                }
            }
        }

        return closed;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        // check every cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!vis[i][j] && grid[i][j] == 0) {

                    // one DFS = one complete island
                    if(dfs(i, j, vis, grid, delrow, delcol)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};