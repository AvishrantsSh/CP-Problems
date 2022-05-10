class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);    
        return ans;
    }
    
    void solve(vector<int>& arr, int target, int i){
        int z = i;
        if(target < 0) return;
        
        if(target == 0) {
            ans.push_back(x);
            return;
        }
        
        for(; i < arr.size(); i++){
            if(arr[i] == arr[i-1])
                continue;
            x.push_back(arr[i]);
            solve(arr, target - arr[i], i+1);    
            x.pop_back();
        }
    }
};