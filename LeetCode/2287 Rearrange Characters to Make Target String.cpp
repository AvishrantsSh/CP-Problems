class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        int res = INT_MAX;
        vector<char> scount (26, 0), tcount (26, 0);
        for(auto &ch: s)
            scount[ch - 'a']++;
        
        for(auto &ch: t)
            tcount[ch - 'a']++;
        
        for(auto &ch: t)
            res = min(res, scount[ch - 'a']/tcount[ch - 'a']);
        
        return res;
    }
};