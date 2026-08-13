class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int count=0;

        for(auto it:m){
            int freq=it.second;
            count+= freq * (freq - 1) / 2;
        }

return count;
    }
};