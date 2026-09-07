class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0)
        return false;

        if(n==1)
        return true;

        if(n%4!=0)
        return false;
        return isPowerOfFour(n/4);
       

// return n>0 &&
// (n&(n-1))==0 &&
// (n-1)%3==0;


    }
};