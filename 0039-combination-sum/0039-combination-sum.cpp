class Solution {
public:
    void solve(vector<int>& candidates, int idx, int n,
               vector<int>& diary, vector<vector<int>>& res,
               int target, int sum) {

        if (sum == target) {
            res.push_back(diary);
            return;
        }

        if (idx == n || sum > target)
            return;

        // Don't take candidates[idx]
        solve(candidates, idx + 1, n, diary, res, target, sum);

        // Take candidates[idx]
        if (sum + candidates[idx] <= target) {
            diary.push_back(candidates[idx]);
            sum += candidates[idx];

            // idx stays same because we can reuse the element
            solve(candidates, idx, n, diary, res, target, sum);

            diary.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;

        vector<int> diary;
        vector<vector<int>> res;

        solve(candidates, 0, n, diary, res, target, sum);

        return res;
    }
};