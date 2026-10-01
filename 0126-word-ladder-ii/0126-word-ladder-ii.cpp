class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return result;

        // Step 1: BFS to compute the shortest distance of each word from beginWord
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                q.pop();
                int d = dist[cur];
                string next = cur;
                for (int i = 0; i < (int)next.size(); i++) {
                    char orig = next[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        next[i] = c;
                        if (dict.count(next) && !dist.count(next)) {
                            dist[next] = d + 1;
                            if (next == endWord) found = true;
                            q.push(next);
                        }
                    }
                    next[i] = orig;
                }
            }
        }

        if (!found) return result;

        // Step 2: DFS backwards from endWord to beginWord, only moving to words one level closer
        vector<string> path = {endWord};
        dfs(endWord, beginWord, dist, dict, path, result);
        return result;
    }

private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, int>& dist, unordered_set<string>& dict,
             vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        int d = dist[word];
        string next = word;
        for (int i = 0; i < (int)next.size(); i++) {
            char orig = next[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                next[i] = c;
                auto it = dist.find(next);
                if (it != dist.end() && it->second == d - 1) {
                    path.push_back(next);
                    dfs(next, beginWord, dist, dict, path, result);
                    path.pop_back();
                }
            }
            next[i] = orig;
        }
    }
};