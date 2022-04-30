class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minVal = INT_MAX, dis=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                int d = sum-target;
                if (d == 0) return target;
                else if (d < 0) l++;
                else r--;
                
                if (dis > abs(d)){
                    minVal = sum;
                    dis = abs(d);
                }

            }
            while(i < n - 2 && nums[i] == nums[i+1])
                i++;
        }
        return minVal;
    }
};