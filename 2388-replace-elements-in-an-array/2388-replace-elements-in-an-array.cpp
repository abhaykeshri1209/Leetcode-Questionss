class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;

        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }

 

        for(int j=0;j<operations.size();j++){
            int a= operations[j][0];
            int b= operations[j][1];

            if(pos.find(a) != pos.end()) {
                nums[pos[a]] = b;
                pos[b] = pos[a];
  
                 }
        }
        return nums;
   
    }
};