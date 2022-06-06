// Top-Down Approach
class Solution {
private:
    vector<vector<int>> dp;
public:
    int lcs(string &text1, string& text2, int m, int n){
        if(m == 0 || n == 0) return 0;
        
        if (dp[m-1][n-1] != -1) return dp[m-1][n-1];

        if(text1[m - 1] == text2[n - 1])
            return dp[m-1][n-1] = 1 + lcs(text1, text2, m - 1, n - 1);
        
        return dp[m-1][n-1] = max(lcs(text1, text2, m-1, n), lcs(text1, text2, m, n-1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return lcs(text1, text2, m, n);
    }
};

// Bottom-Up Approach
class Solution 
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (text1[i] == text2[j]) dp[i+1][j+1] = 1 + dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        return dp[m][n];
    }
};

// Space Optimized
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            bool index = i % 2;
            for(int j = 0; j < n; j++){
                if (text1[i] == text2[j]) dp[1-index][j+1] = 1 + dp[index][j];
                else dp[1-index][j+1] = max(dp[index][j+1], dp[1-index][j]);
            }
        }
        
        return dp[m%2][n];
    }
};