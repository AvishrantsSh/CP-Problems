class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), l = 1, r = 1;
        vector<int> res(n, 1);
        
        for(int i = 0 ; i < n; i++){
            res[i] *= l;
            l *= nums[i];
            res[n-i-1] *= r;
            r *= nums[n-i-1];
        }
        return res;
    }
};