class Solution {
public:
    vector<int> d = {0, 1};
    int fib(int n) {
        for(int i = 2; i <= n; i++)
            d.push_back(d[i-1] + d[i-2]);
        
        return d[n];
    }
};