class Solution {
public:
    int addDigits(int num) {

        
         
         while(num>=10){
int add=0;
        while(num>0){

            int digit=num%10;
            add+=digit;
            num=num/10;   

        }
        num=add;
         }
        return num;
        
    }
};