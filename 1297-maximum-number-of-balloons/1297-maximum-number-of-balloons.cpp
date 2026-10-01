class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;

        for(char c : text)
            m[c]++;

        int ans = INT_MAX;

        ans = min(ans, m['b'] / 1);
        ans = min(ans, m['a'] / 1);
        ans = min(ans, m['l'] / 2);
        ans = min(ans, m['o'] / 2);
        ans = min(ans, m['n'] / 1);

        return ans;
    }
};