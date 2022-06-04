// Backtracking Solution
class Solution {
private:
    int res = 0;
    void solve(vector<int>& nums, int index, int curr){
        if(index == nums.size()){
            res += curr;
            return;
        }
        // If we choose the element at index
        solve(nums, index + 1, curr ^ nums[index]);
        // If we don't choose the element at index
        solve(nums, index + 1, curr);
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return res;
    }
};

// Optimization
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto &num: nums) res |= num;
        return res << nums.size() - 1;
    }
};