class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> dist(r, vector<int>(c, 1e9));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        dist[0][0] = 0;

        pq.push({0, 0, 0});

        while(!pq.empty()) {

            int effort, row, col;

            tie(effort, row, col) = pq.top();
            pq.pop();

            if(row == r-1 && col == c-1) {
                return effort;
            }

            for(int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < r &&
                   newCol >= 0 && newCol < c) {

                    int heightDifference =
                        abs(heights[row][col] -
                            heights[newRow][newCol]);

                    int newEffort =
                        max(effort, heightDifference);

                    if(newEffort < dist[newRow][newCol]) {

                        dist[newRow][newCol] = newEffort;

                        pq.push({
                            newEffort,
                            newRow,
                            newCol
                        });
                    }
                }
            }
        }

        return 0;
    }
};