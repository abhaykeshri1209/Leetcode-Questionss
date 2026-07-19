class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";

        string ans = "";
        string first = strs[0];

        for (int i = 0; i < first.length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != first[i]) {
                    return ans;
                }
            }
            ans += first[i];
        }

        return ans;
    }
};
