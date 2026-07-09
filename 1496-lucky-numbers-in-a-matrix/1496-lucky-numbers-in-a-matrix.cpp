class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;

        for (int i = 0; i < matrix.size(); i++) {

            int mini = INT_MAX;
            int colIndex = -1;

            
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    colIndex = j;
                }
            }

            bool isMax = true;
            for (int row = 0; row < matrix.size(); row++) {
                if (matrix[row][colIndex] > mini) {
                    isMax = false;
                    break;
                }
            }

            if (isMax) {
                ans.push_back(mini);
            }
        }

        return ans;
    }
};