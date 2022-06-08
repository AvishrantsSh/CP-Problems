class Solution {
public:
    int removePalindromeSub(string s) {
        /*
            Only two cases are possible:
            1. Return 1 if string is a palindrome.
            2. Return 2 if string is not a palindrome. We can remove all a's followed by all                  b's to remove all palindromic subsequence.
        */
        
        return 2 - equal(s.begin(), s.end(), s.rbegin());
    }
};