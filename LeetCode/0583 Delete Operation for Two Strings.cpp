class Solution {
public:
    int lcs(string& w1, string& w2){
        int m = size(w1), n = size(w2);
        vector<vector<int>> dp (2, vector<int>(n + 1));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                bool bi = i % 2, bj = j % 2;
                dp[bi][j] = w1[i-1] == w2[j-1] ? 1 + dp[1-bi][j-1]: max(dp[bi][j-1], dp[1-bi][j]);
            }
        }
        return dp[m % 2][n];
    }
    
    int minDistance(string word1, string word2) {
        return size(word1) + size(word2) - 2*lcs(word1, word2);
    }
};