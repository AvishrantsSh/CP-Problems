class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        int wcount = 0, index = -1;
        unordered_map<string, int> mp;
        for(int i = 0; i < s.size(); i++){
            int tmp = count(m[i].begin(), m[i].end(), ' ') + 1;
            mp[s[i]] += tmp;
            if (wcount < mp[s[i]]){
                wcount = mp[s[i]];
                index = i;
            }
            
            else if (wcount == mp[s[i]] && s[index] < s[i]) index = i;
        }
        return s[index];
    }
};