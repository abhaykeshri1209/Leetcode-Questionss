class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             int delrow[], int delcol[]) {

        // mark current cell visited
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // check 4 directions
        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // boundary check + not visited + land
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 1. Start DFS from boundary 1s
        // first row + last row
        for(int j = 0; j < m; j++) {

            // first row
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid, delrow, delcol);
            }

            // last row
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, vis, grid, delrow, delcol);
            }
        }

        // first column + last column
        for(int i = 0; i < n; i++) {

            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid, delrow, delcol);
            }

            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, vis, grid, delrow, delcol);
            }
        }

        // 2. Count remaining unvisited 1s
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};