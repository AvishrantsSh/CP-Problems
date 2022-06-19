class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length(), ans = 0, j = 0;
        long long sum = 0;
        for(int i = n - 1; i>= 0; i--, j++){
            if(s[i] - '0'){
                if(j < 31 and sum + (1LL<<j) <= k){
                    sum += 1LL << j;
                    ans++;
                }
            }
            else ans++;
        }
        
        return ans;
    }
};