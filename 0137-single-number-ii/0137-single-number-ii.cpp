class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;

if (n == 1) {
    return nums[0];
}

for (int i = 1; i < n; i += 3) {

    if (nums[i] != nums[i - 1]) {
        ans = nums[i - 1];
        return ans;
    }
}

return nums[n - 1];
       
    }
};