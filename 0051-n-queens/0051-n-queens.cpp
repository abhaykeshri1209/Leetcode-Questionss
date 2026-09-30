class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {

        // All queens placed
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for(int j = 0; j < n; j++) {

            if(isSafe(board, row, j, n)) {

                // Place queen
                board[row][j] = 'Q';

                // Move to next row
                nQueens(board, row + 1, n, ans);

                // Backtrack
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        nQueens(board, 0, n, ans);

        return ans;
    }
};