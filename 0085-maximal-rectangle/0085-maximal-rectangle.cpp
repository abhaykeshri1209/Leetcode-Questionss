class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Next Smaller on Right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // Next Smaller on Left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> height(col, 0);

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j]++;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};