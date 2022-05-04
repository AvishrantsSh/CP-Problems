class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        
        if(k < nums[0]) return 0;
        if (n > 1 && k > nums[n-1] + nums[n-2]) return 0;
            
        int l = 0, r = n - 1;
        while(l < r){
            if(nums[l] + nums[r] < k) l++;
            else if(nums[l] + nums[r] > k) r--;
            else count++, l++, r--;
        }
        return count;
    }
};