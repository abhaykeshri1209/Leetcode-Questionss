class Solution {
public:

    void solve(int index, string &digits, string &current,
               vector<string> &ans, unordered_map<char, string> &mp) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        for (char ch : mp[digits[index]]) {

            current.push_back(ch);

            solve(index + 1, digits, current, ans, mp);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> mp = {
            {'2',"abc"}, {'3',"def"},
            {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> ans;
        string current;

        solve(0, digits, current, ans, mp);

        return ans;
    }
};