class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcut, vector<int>& vcut) {
        sort(hcut.begin(), hcut.end());
        sort(vcut.begin(), vcut.end());
        int max_h = max(hcut[0], h - hcut.back());
        int max_v = max(vcut[0], w - vcut.back());
        for(int i = 0; i < hcut.size() - 1; i++)
            max_h = max(max_h, hcut[i+1] - hcut[i]);
                        
        for(int i = 0; i < vcut.size() - 1; i++)
            max_v = max(max_v, vcut[i+1] - vcut[i]);
                        
        return (long) max_h * max_v % 1000000007;
    }
};