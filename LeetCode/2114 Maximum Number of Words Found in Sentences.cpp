class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxLen = 0;
        for(auto &s: sentences){
            maxLen = max((int)count(s.begin(), s.end(), ' '), maxLen);
        }
        
        return maxLen + 1;
    }
};