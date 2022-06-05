class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[150] = {};
        int maxlen = 0, pointer = 0;
        for (int i = 0; i < s.length(); i++) {
            int x = s[i];
            arr[x] += 1;
            
            while(arr[x] > 1){
                arr[s[pointer]] -= 1;
                pointer += 1;
            }

            maxlen = max(i - pointer + 1, maxlen);
        }
        return maxlen;
    }
};