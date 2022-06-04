// Backtracking Solution
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> soln;
    
    bool is_safe(int &row, int &col, int &n){
        // Check if queen exists in same column
        for(int i = 0; i < row; i++)
            if (soln[i][col] == 'Q')
                return false;
        
        // Check if queen exists in top left diagonal
        for(int i = min(row, col); i >= 0; i--)
            if (soln[row-i][col-i] == 'Q')
                return false;
        
        // Check if queen exists in top right diagonal
        for(int i = min(row, n - col - 1) ; i >= 0; i--)
            if (soln[row-i][col+i] == 'Q')
                return false;
        
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        soln = vector<string> (n, string(n, '.'));
        solve(0, n);
        return ans;
    }
    
    void solve(int row, int n){
        if(row == n){
            ans.push_back(soln);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (is_safe(row, i, n)){
                soln[row][i] = 'Q';
                solve(row + 1, n);
                soln[row][i] = '.';
            }
        }
    }
};

// Time Optimization
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> soln;
    // We can store status of all three cases in a single vector
    vector<vector<bool>> status;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        soln = vector<string> (n, string(n, '.'));
        status = vector<vector<bool>>(3, vector<bool>(2*n, false));
        solve(0, n);
        return ans;
    }
    
    void solve(int row, int n){
        if(row == n){
            ans.push_back(soln);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (not(status[0][i] or status[1][i - row + n] or status[2][i+row])){
                soln[row][i] = 'Q';
                status[0][i] = true, status[1][i - row + n] = true, status[2][i+row] = true;
                solve(row + 1, n);
                status[0][i] = false, status[1][i - row + n] = false, status[2][i+row] = false;
                soln[row][i] = '.';
            }
        }
    }
};