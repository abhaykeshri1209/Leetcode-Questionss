class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 0;

            while(n > 0) {
                int digit = n % 10;
                sum += digit;
                n = n / 10;
            }

            if(sum == i) {
                mini = min(mini, i);
            }
        }

        if(mini == INT_MAX) {
            return -1;
        }

        return mini;
    }
};