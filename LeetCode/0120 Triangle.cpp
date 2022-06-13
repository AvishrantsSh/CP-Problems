// Top-Down Approach
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& t, int level, int n){
        if(level >= t.size() or n >= t[level].size()) return 0;
        if(dp[level][n] != -1) return dp[level][n];
        
        return dp[level][n] = t[level][n] + min(solve(t, level+1, n), solve(t, level+1, n+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        return solve(triangle, 0, 0);
    }
};

// Iterative Top-Down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int level = triangle.size() - 2; level >= 0; level--) // start from bottom-1 level
		for(int i = 0; i <= level; i++)
			triangle[level][i] += min(triangle[level + 1][i], triangle[level + 1][i + 1]);
	    return triangle[0][0]; // lastly t[0][0] will contain accumulated sum of minimum path
    }
};