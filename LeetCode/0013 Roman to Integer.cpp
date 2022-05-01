class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n =s.length();
        int roman[26];
        roman['I'-'A']=1;
        roman['V'-'A']=5;
        roman['X'-'A']=10;
        roman['L'-'A']=50;
        roman['C'-'A']=100;
        roman['D'-'A']=500;
        roman['M'-'A']=1000;
        
        for(int i = 0; i < n; i++){
            int cur = roman[s[i] - 'A'];
            int right = (i+1 < n)?roman[s[i+1] - 'A']:0;
            if(cur < right)
                ans -= cur;
            else
                ans += cur;
        }
        return ans;
    }
};