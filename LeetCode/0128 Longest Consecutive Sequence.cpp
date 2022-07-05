class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 1;
        for(auto &i: nums){
            if(!s.count(i)) continue;
            s.erase(i);
            int prev = i-1, next = i+1;
            while (s.count(prev)) s.erase(prev--);
            while (s.count(next)) s.erase(next++);
            ans = max(ans, next - prev - 1);
        }
        
        return ans;
    }
};