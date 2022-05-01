// Using recursion
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> x = generate(numRows - 1);
        vector<int> tmp(1,1);
        
        for (int i = 1; i < x.back().size(); i++)
            tmp.push_back(x.back()[i-1] + x.back()[i]);
        
        tmp.push_back(1);
        x.push_back(tmp);
        return x;
    }
};

// Using iteration
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> x(numRows, {1});
        for(int i = 1; i < numRows; i++){
            for(int j =1; j < i; j++)
                x[i].push_back(x[i-1][j-1]+x[i-1][j]);
            x[i].push_back({1});
        }
    return x;
    }
};