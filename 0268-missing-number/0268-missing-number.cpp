class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());  

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] != i) {
        //         return i;   
        //     }
        // }

        // return nums.size(); 

        int ans = nums.size();

for(int i = 0; i < nums.size(); i++)
{
    ans ^= i;
    ans ^= nums[i];
}

return ans;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//        int ans=n;
       

//        for(int i=0;i<n;i++){

//         if(nums[i] !=i){
//             ans=i;
//         }
//        }
//        return ans;
//     }
// };