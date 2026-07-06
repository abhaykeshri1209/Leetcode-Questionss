class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
 int positive =0;
 int negative=0;
 vector<int>ans;

 while(positive<nums.size() && negative<nums.size()){

while (positive < nums.size()&& nums[positive] < 0)
    positive++;

while (negative < nums.size() && nums[negative] > 0)
    negative++;

    ans.push_back(nums[positive]);
positive++;

ans.push_back(nums[negative]);
negative++;

 }
 return ans;


    }
};



//       vector<int> positive;
//         vector<int> negative;
        
        
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] > 0)
//                 positive.push_back(nums[i]);
//             else
//                 negative.push_back(nums[i]);
//         }
//         vector<int>result;
//         for(int i=0;i<positive.size(); i++){
//             result.push_back(positive[i]);
//             result.push_back(negative[i]);
//         }

    
//  return result;