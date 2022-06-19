class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(5, 0), upper(26, 0);
        for(auto &c: s){
            if(c >= 'a' and c <= 'z') lower[c-'a'] = true;
            else upper[c-'A'] = true;
        }
        string ans = "";
        for(int i = 25; i >= 0; i--){
            if(upper[i] and lower[i])
                return ans += 'A' + i;
        }
        
        return "";
    }
};