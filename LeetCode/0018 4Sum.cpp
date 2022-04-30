# define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if((ll)nums[i]+(ll)nums[j]+(ll)nums[j+1]+(ll)nums[j+2] > target) break;
                if((ll)nums[i]+(ll)nums[j]+(ll)nums[n-2]+(ll)nums[n-1] < target) continue;

                int l = j + 1, r = n - 1;
                while(l < r){
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r];
                    if (sum < target){
                        while(l < r && nums[l] == nums[l+1])
                            l++;
                        l++;
                    }
                    else if(sum > target){
                        while(l < r && nums[r] == nums[r-1])
                            r--;
                        r--;
                    }
                    else{
                        sol.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1])
                            l++;
                        while(l < r && nums[r] == nums[r-1])
                            r--;
                        l++, r--;
                    }
                }
            }
        }
        return sol;
    }
};