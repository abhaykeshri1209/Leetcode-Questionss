class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0;
        int count=0;

        for(int right=0;right<k;right++){
            if(blocks[right]=='W')
                count++;
           
        }
        int ans=count;

        for(int right=k;right<blocks.size();right++){

            if(blocks[right]=='W'){
                count++;
            }
              if(blocks[left]=='W'){
                count--;
            }
            left++;
            ans=min(ans,count);
        }
        return ans;
    }
};