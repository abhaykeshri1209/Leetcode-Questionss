class Solution {
public:
    int countCommas(int n) {

        int commas=0;

        if(n<1000){
            
            return commas;
        }

        if(n>1000000){
            commas=(n-1000000+1)*2;
        }

        else

         commas=n-1000+1;
   
   return commas;
       
        
    }
};