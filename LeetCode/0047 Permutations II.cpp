class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
    
    void solve(vector<int> nums, int i){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        int ref = i;
        for(; i < nums.size(); i++){
            int j = ref;
            while(j < i && nums[j] != nums[i])
                j++;
            
            if (j != i) continue;
            swap(nums[ref], nums[i]);
            solve(nums, ref+1);
            
        }
    }
};