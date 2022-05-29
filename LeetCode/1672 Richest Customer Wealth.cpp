class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(auto &user: accounts){
            maxWealth = max(maxWealth, accumulate(user.begin(), user.end(), 0));
        }
        return maxWealth;
    }
};