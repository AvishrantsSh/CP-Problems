// Using backtracking
class Solution {
public:
    int count = 0;
    string x = "";
    string ref="aeiou";

    int countVowelStrings(int n) {
        solve(n, 0);
        return count;
    }
    void solve(int n, int i){
        if(n <= 0){
            count++;
            return;
        }
        for(; i < ref.length(); i++){
            x += ref[i];
            solve(n-1, i);
            x.pop_back();
        }
    }
};

// Using Meth
class Solution {
public:
    int countVowelStrings(int n) {
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
};