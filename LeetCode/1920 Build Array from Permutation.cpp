// Approach - 1(O(N) Space Complexity)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(auto &i: nums)
            ans.push_back(nums[i]);
        
        return ans;
    }
};

// Approach - 2 (O(1) Space Complexity)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

		for(auto &i : nums)
			i += n*(nums[i] % n);

		for(int i = 0 ; i < n ; i++)
			nums[i] = nums[i]/n;
		
		return nums;
    }
};