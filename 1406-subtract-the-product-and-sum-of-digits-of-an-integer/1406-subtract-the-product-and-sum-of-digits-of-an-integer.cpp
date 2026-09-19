class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int mul=1;
        int result=0;

        while(n>0){
            int digit=n%10;
            sum+=digit;
             mul*=digit;
            n=n/10;
        }

      
        result= mul-sum;
        return result;

    }
};