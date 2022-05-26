class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        int n = gS.size();
        vector<vector<int>> ans, tmp (n+1);
        
        for(int i = 0; i < n; i++){
            tmp[gS[i]].push_back(i);
            
            if(tmp[gS[i]].size() == gS[i]){
                ans.push_back(tmp[gS[i]]);
                tmp[gS[i]] = {};
            }
        }
        return ans;
    }
};