class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        int n = p.length();
        if(n < 8) return false;
        
        bool lcase = false, ucase = false, dig = false, sp_car = false;
        for(int i = 0; i < n; i++){
            if(i != n and p[i] == p[i+1]) return false;
 
			if(p[i] >= 'a' and p[i] <= 'z') lcase = true;
            else if(p[i] >= 'A' and p[i] <='Z') ucase = true;
            else if(isdigit(p[i])) dig = true;
            else sp_car = true;
        }
        return lcase & ucase & dig & sp_car;
    }
};