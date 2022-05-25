class Solution {
static bool cmp(vector<int>& a, vector<int>& b){
    return (a[0] == b[0])?a[1] > b[1]: a[0] < b[0];
}
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), cmp);
        vector<int> ans;
        
        for(auto &i:env){
            int ele = i[1];
            int idx = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();
            if(idx >= ans.size()) ans.push_back(ele);
            else ans[idx] = ele;
        }
        
        return ans.size();
    }
};