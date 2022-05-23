// Best Solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        for(int i = 2; i < n; i++)
            cost[i] += min(cost[i-1], cost[i-2]);
        
        return min(cost[n-1], cost[n-2]);
    }
};

// O(1) space solution -- by me :)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int p1 = 0, p2 = 0, res = 0;
        for(int i = 2; i <= n; i++)
            res = min(p2 + cost[i-1], p1 + cost[i-2]), p1 = p2, p2 = res;
        
        return res;
    }
};