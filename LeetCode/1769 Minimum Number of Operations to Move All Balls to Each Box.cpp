class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length(), lcount = 0, rcount = 0;
        vector<int> ans(n, 0);
        for(int j = 0; j < n; j++){
            if(boxes[j] - '0'){
                ans[0] += abs(j);
                rcount++;
            }
        }
        rcount -= boxes[0] - '0';
        
        for(int i = 1; i < n; i++){
            lcount += boxes[i-1] - '0';
            ans[i] = ans[i-1] + lcount - rcount;
            rcount -= boxes[i] - '0';
        }
        return ans;
    }
};