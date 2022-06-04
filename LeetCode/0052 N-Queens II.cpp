// Backtracking
class Solution {
public:
    int ans = 0;
    vector<vector<bool>> sol;
    
    int totalNQueens(int n) {
        sol = vector<vector<bool>> (n , vector<bool> (n, false));
        solve(0, n);
        return ans;
    }
    
    bool is_safe(int &row, int &col, int &n){
        
        // Check if queen exists in same column
        for(int i = 0; i < row; i++)
            if(sol[i][col]) return false;
        
        // Check if queen exists in top left diagonal
        for(int i = min(row, col); i >= 0; i--)
            if(sol[row - i][col - i]) return false;
        
        // Check if queen exists in top right diagonal
        for(int i = min(row, n - col - 1); i >= 0; i--)
            if(sol[row - i][col + i]) return false;
        
        return true;
    }
    
    void solve(int row, int n){
        if(row == n){
            ans++;
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(is_safe(row, i, n)){
                sol[row][i] = true;
                solve(row + 1, n);
                sol[row][i] = false;
            }
        }
    }
};

// Time Optimization
class Solution {
public:
    int ans = 0;
    vector<vector<bool>> sol;
    vector<vector<bool>> status;
    
    int totalNQueens(int n) {
        sol = vector<vector<bool>> (n , vector<bool> (n, false));
        status = vector<vector<bool>> (3 , vector<bool> (2*n, false));
        solve(0, n);
        return ans;
    }
    
    void solve(int row, int n){
        if(row == n){
            ans++;
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(status[0][i] or status[1][i - row + n] or status[2][i + row]) continue;
            sol[row][i] = true, status[0][i] = true, status[1][i - row + n] = true, status[2][i+row] = true;
            solve(row + 1, n);
            sol[row][i] = false, status[0][i] = false, status[1][i - row + n] = false, status[2][i+row] = false;
        }
    }
};