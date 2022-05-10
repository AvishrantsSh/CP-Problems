class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);    
        return ans;
    }
    
    void solve(vector<int>& arr, int target, int i){
        if(target < 0) return;
        
        if(target == 0) {
            ans.push_back(x);
            return;
        }
        
        for(; i < arr.size(); i++){
            x.push_back(arr[i]);
            solve(arr, target - arr[i], i);
            x.pop_back();
        }
    }
    
};