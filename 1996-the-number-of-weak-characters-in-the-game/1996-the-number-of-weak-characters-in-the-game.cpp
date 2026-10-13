class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
    return a[1] > b[1];
} else {
    return a[0] < b[0];
}
        });

        stack<int> st; // only defense needed
        int count = 0;

        for (auto& p : properties) {
            while (!st.empty() && st.top() < p[1]) {
                count++;
                st.pop();
            }
            st.push(p[1]);
        }
        return count;
    }
};