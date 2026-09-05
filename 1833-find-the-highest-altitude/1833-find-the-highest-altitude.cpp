class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n = gain.size();

        vector<int> alti(n + 1);

        alti[0] = 0;

        for (int i = 1; i <= n; i++) {
            alti[i] = alti[i - 1] + gain[i - 1];
        }

        int maxi = INT_MIN;

        for (int i = 0; i < alti.size(); i++) {
            maxi = max(maxi, alti[i]);
        }

        return maxi;
    }
};