// Approach - 1 (Using frequencies)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> f(26, 0);
        int diffs = 0;
        for(int i = 0; i < s1.length(); i++){
            if (s1[i] != s2[i]) diffs++;
            f[s1[i]-'a'] += 1;
            f[s2[i]-'a'] -= 1;
        }
        if (diffs == 0) return true;
        if (diffs != 2) return false;
        for(auto &i : f)
            if(i)
                return false;
     
        return true;
    }
};

// Approach - 2 (without measuring frequencies)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int d = 0, i1 = 0, i2 = 0;
        for(int i = 0; i < s1.length(); i++)
            if (s1[i] != s2[i]){
                d++;
                if(!i1) i1 = i; else i2 = i;
            }
        if (d == 0) return true;
        if (d == 2 && (s1[i1] == s2[i2] && s1[i2] == s2[i1])) return true;
        return false;
    }
};