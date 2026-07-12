class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;

        }
        int ans=0;

        for(auto it:hash){
            if(it.second>=2){
                ans=it.first;
            }
        }
        return ans;
    }
};