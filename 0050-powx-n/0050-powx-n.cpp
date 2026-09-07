class Solution {
public:
    double myPow(double x, long long n) {

        if(n == 0)
            return 1;

        if(n == 1)
            return x;

        if(n < 0)
            return 1 / myPow(x, -n);

        if(n % 2 == 0) {
            double half = myPow(x, n / 2);
            return half * half;
        }
        else {
            double half = myPow(x, n / 2);
            return x * half * half;
        }
    }
};