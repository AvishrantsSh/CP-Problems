// Top-Down Approach
class Solution {
int dp[601][101][101] = {};
    
public:
    int sub(vector<pair<int, int>> &a, int index, int zeros, int ones){
        int n = a.size();
        if(index == n or (ones == 0 and zeros == 0)) return 0;
        
        if(dp[index][zeros][ones] != 0)
            return dp[index][zeros][ones];
        
        if(a[index].first > zeros or a[index].second > ones)  
            return (dp[index][zeros][ones] = sub(a , index+1 , zeros , ones));
        
        int include = 1 + sub(a, index+1, zeros - a[index].first, ones - a[index].second);
        int exclude = sub(a, index+1, zeros, ones);
        
        return (dp[index][zeros][ones]=max(include , exclude));     
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> a;
        for(auto i : strs)
        {
            int one = 0, zero = 0;
            for(auto j : i)
                (j == '1') ? one++ : zero++;
            a.push_back({zero , one});
        }
        
        int ans = sub(a, 0, zeros, ones);
        return ans;
};

// Bottom-up Approach
class Solution {  
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1));
        for(auto &s: strs){
            int ones = count(s.begin(), s.end(),'1');
            int zeros = s.length() - ones;
            for(int i = m; i >= zeros; i--)
                for(int j = n ; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
        }
        return dp[m][n];
    }
};