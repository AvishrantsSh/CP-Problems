class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n = sentence.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += sentence[i];
            if(sentence[i] == '$' && (i == 0 || sentence[i-1] == ' ')){
                long num = 0, j = i+1;
                for(; j < n and isdigit(sentence[j]); j++)
                    num = num*10 + (sentence[j] - '0');
                    
                if(j == i+1 || (j < n and sentence[j] != ' ')) continue;
                string tmp = to_string(ceil(num * (100.0 - discount)) / 100.0 + 0.001);
                ans += tmp.substr(0, tmp.find('.') + 3);
                i = j-1;
            }
        }
        
        return ans;
    }
};