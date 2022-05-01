// Approach - 1 (Using stacks)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        for(auto &ch : s){
            if (ch == '#'){
                if (!s1.empty()) s1.pop();
                continue;
            } 
            else s1.push(ch);
        }
        for(auto &ch : t){
            if (ch == '#'){
                if (!s2.empty()) s2.pop();
                continue;
            } 
            else s2.push(ch);
        }
        return s1 == s2;
    }
};

// Approach - 2 (Overwriting same string)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k1 = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '#')
                k1 = max(0, k1-1);
            else{
                if(k1 != i)
                    s[k1] = s[i];
                k1++;
            }
        }
        int k2 = 0;
        for(int i = 0; i < t.size(); i++){
            if (t[i] == '#')
                k2 = max(0, k2-1);
            else{
                if(k2 != i)
                    t[k2] = t[i];
                k2++;
            }
        }
        if(k1 != k2) return false;
        while(k1){
            k1--;
            if (s[k1] != t[k1]) return false;
        }
        return true;
    }
};