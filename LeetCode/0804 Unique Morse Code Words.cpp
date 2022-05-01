class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto &w : words){
            string ans = "";
            for(auto& ch: w) ans += morse[ch-'a'];
            s.insert(ans);
        }
        return s.size();
    }
};