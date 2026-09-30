class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if (dead.find("0000") != dead.end()) {
            return -1;
        }

        queue<pair<string, int>> q;

        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == target) {
                return steps;
            }

            for (int i = 0; i < 4; i++) {

                char original = word[i];

                // Move digit forward
                word[i] = (original == '9') ? '0' : original + 1;

                if (dead.find(word) == dead.end() &&
                    vis.find(word) == vis.end()) {

                    vis.insert(word);
                    q.push({word, steps + 1});
                }

                // Move digit backward
                word[i] = (original == '0') ? '9' : original - 1;

                if (dead.find(word) == dead.end() &&
                    vis.find(word) == vis.end()) {

                    vis.insert(word);
                    q.push({word, steps + 1});
                }

                // Restore
                word[i] = original;
            }
        }

        return -1;
    }
};