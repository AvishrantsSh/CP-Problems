class Solution {
public:
    double myPow(double x, long n) {
        if(x == 1 || n == 0) return 1;
        if(n < 0) n = -n, x = 1/x;
        double tmp = 1;
        while(n){
            if(n & 1) tmp *= x;
            x *= x;
            n >>= 1;
        }
        return tmp;
    }
};