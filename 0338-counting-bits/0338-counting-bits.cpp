class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);

        for(int i=0;i<=n;i++){
             int count=0;
             int x=i;

             while (x > 0) {
          int bit = x% 2;

           if (bit == 1) {
             count++;
            }

            x = x / 2;
           
       }
       ans[i]=count;
        }
        return ans;
    }
};