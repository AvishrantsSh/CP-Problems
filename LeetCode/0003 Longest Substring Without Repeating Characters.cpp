class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[150] = {};
        int maxlen = 0, pointer = 0, tmplen = 0;
        for (int i = 0; i < s.length(); i++) {
            int x = s[i];
            arr[x] += 1;
            tmplen += 1;
            
            while(arr[x] > 1){
                arr[s[pointer]] -= 1;
                tmplen -= 1;
                pointer += 1;
            }

            maxlen = maxlen > tmplen ? maxlen : tmplen;
        }
        return maxlen;
    }
};