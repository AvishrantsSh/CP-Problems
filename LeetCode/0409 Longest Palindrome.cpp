class Solution {
public:
    int longestPalindrome(string s) {
        int odd_groups = 0;
        int freq[60] = {0};
        for(auto &c: s){
            freq[c - 'A']++;
            if (freq[c-'A'] % 2) odd_groups++;
            else odd_groups--;
        }
        
        return s.length() - odd_groups + (odd_groups > 0);
    }
};