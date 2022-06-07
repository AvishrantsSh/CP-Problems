class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int> ());
        int start = nums[0], ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(start - nums[i] > k){
                ans++;
                start = nums[i];
            }
        }
        
        return ans+1;
    }
};