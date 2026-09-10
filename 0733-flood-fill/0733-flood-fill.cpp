class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& image,
             int oldColor, int color) {
        
        int n = image.size();
        int m = image[0].size();

        image[row][col] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == oldColor) {
                
                dfs(nrow, ncol, image, oldColor, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                   int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};