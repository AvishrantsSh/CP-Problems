class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> degree (n, 0);
        for(int i = 0; i < roads.size(); i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        
        sort(degree.begin(), degree.end());
        for(int i = 0; i < n; i++)
            ans += (long long)degree[i] * (i+1);
        
        return ans;
    }
};