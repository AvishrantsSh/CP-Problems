class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (r+l)/2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};