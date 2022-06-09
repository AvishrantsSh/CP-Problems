// Kadane Algorithm
class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        int prev = 0, ans = INT_MIN;
        for(auto &i : nums)
            prev = max(i, prev + i),
            ans = max(ans, prev);
        
        return ans;
    }
};

// Dynamic Programming
class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        
        
        return *max_element(dp.begin(), dp.end());
    }
};