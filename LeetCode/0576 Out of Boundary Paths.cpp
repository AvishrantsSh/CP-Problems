// Backtracking Solution
class Solution {
public:
    int mod = 1e9+7;
    int backtrack(int& m, int& n, int moves, int row, int col){
        if(row < 0 || col < 0 || row >= m || col >= n)
            return 1;
        
        if(moves == 0) return 0;
        
        int res = 0;
        res = (res + backtrack(m, n, moves - 1, row + 1, col)) % mod;
        res = (res + backtrack(m, n, moves - 1, row - 1, col)) % mod;
        res = (res + backtrack(m, n, moves - 1, row, col + 1)) % mod;
        res = (res + backtrack(m, n, moves - 1, row, col - 1)) % mod;
        return res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return backtrack(m, n, maxMove, startRow, startColumn);
    }
};

// Top-Down DP
class Solution {
public:
    int mod = 1e9+7;
    int backtrack(int& m, int& n, int moves, int row, int col, vector<vector<vector<int>>> & dp){
        if(row < 0 || col < 0 || row >= m || col >= n)
            return 1;
        
        if(moves == 0) return 0;
        if(dp[moves][row][col] != -1) return dp[moves][row][col];
        
        int res = 0;
        res = (res + backtrack(m, n, moves - 1, row + 1, col, dp)) % mod;
        res = (res + backtrack(m, n, moves - 1, row - 1, col, dp)) % mod;
        res = (res + backtrack(m, n, moves - 1, row, col + 1, dp)) % mod;
        res = (res + backtrack(m, n, moves - 1, row, col - 1, dp)) % mod;
        return dp[moves][row][col] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        return backtrack(m, n, maxMove, startRow, startColumn, dp);
    }
};

