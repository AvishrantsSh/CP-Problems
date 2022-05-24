class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, n = s.length();
        for(auto &c: t){
            if(c == s[i]) i++;
            if(i == n) return true;
        }
        
        return i == n;
    }
};