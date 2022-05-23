class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
    
    void solve(vector<int>& arr, int i){
        if(i == arr.size()){
            ans.push_back(arr);
            return;
        }
        int ref = i;
        for(; i < arr.size(); i++){
            swap(arr[i], arr[ref]);
            solve(arr, ref+1);
            swap(arr[i], arr[ref]);
        }
    }
};