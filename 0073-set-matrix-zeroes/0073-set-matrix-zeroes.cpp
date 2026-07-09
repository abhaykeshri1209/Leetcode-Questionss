class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<pair<int,int>> zeros;

for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(matrix[i][j]==0)
            zeros.push_back({i,j});
    }
}

for(auto p : zeros)
{
    int r = p.first;
    int c = p.second;

    for(int j=0;j<n;j++)
        matrix[r][j]=0;

    for(int i=0;i<m;i++)
        matrix[i][c]=0;
}
       
    }
};





// // int m = matrix.size();
//         int n = matrix[0].size();

//         vector<int> row(m, 0);
//         vector<int> col(n, 0);

//         // mark
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }

   
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(row[i] || col[j]){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }