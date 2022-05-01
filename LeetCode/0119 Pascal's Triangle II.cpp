class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> x(row+1,0);
        x[0] = 1;
        for(int i = 1; i <= row; i++){
            for(int j = i; j ; j--)
                x[j] += x[j-1];
        }
        return x;
    }
};