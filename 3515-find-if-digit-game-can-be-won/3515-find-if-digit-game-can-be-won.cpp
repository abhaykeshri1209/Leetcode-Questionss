class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
         int single=0;
         int doublee=0;
         int alice=0;
         int bob=0;

         for(int i=0;i<nums.size();i++){
            if(nums[i]>9){
                doublee+=nums[i];
            }
            else {
                single+=nums[i];
            }
           
           
         }
        
alice = max(single, doublee);
bob = min(single, doublee);

return alice > bob;
    }
};