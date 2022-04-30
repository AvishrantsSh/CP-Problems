class Solution {
public:
    int myAtoi(string s) {
        long long i = 0, index = 0;
        char c;
        while(s[index] == ' ') index++;
        int sign = (c = s[index]) == '-'? -1 : 1;
        if (sign == -1 || c == '+') index++;
        
        for (;index < s.length(); index++){
            c = s[index];
            int digit = c - '0';
            if (digit > 9 || digit < 0) break;
            if (i > INT_MAX / 10 || (i == INT_MAX/10 && digit > 7))
                return (sign == 1)? INT_MAX: INT_MIN;
            
            i = i*10 + digit;
        }
        
        return (int)sign*i;
    }
};