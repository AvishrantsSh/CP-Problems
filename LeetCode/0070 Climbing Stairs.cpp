class Solution {
public:
    vector<int> x;
    int climbStairs(int n) {
        x.resize(n+1, -1);
        return climb(n);
    }
    int climb(int n){
        if(n <= 1) return 1;
        if(x[n] != -1) return x[n];
        int count = climb(n-1);
        if(n > 1)
            count += climb(n-2);
        return x[n] = count;
    }
};