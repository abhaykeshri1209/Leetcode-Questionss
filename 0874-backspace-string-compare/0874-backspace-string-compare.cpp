class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string result1 = "";
        string result2 = "";

        // Process s
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '#') {

                if (!result1.empty()) {
                    result1.pop_back();
                }

            } else {

                result1.push_back(s[i]);
            }
        }

        for (int j = 0; j < t.size(); j++) {

            if (t[j] == '#') {

                if (!result2.empty()) {
                    result2.pop_back();
                }

            } else {

                result2.push_back(t[j]);
            }
        }
        return result1 == result2;
    }
};