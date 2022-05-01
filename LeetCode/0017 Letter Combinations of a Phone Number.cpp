class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ans = {""};
        const vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(auto digit:digits){
            vector<string> anstemp;
            for(auto ch:map[digit - '0']){
                for(auto r: ans)
                    anstemp.push_back(r+ch);
            }
            ans.swap(anstemp);
        }
        return ans;
        
    }
};