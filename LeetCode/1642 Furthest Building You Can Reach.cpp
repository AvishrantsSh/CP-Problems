class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int totalBricksUsed = 0;
        priority_queue<int> bricksUsed;
        int reach = 0;
        for (; reach < n-1; reach++) {
            if (heights[reach] >= heights[reach+1])
                continue;

            int diff = heights[reach+1] - heights[reach];
        
            if (totalBricksUsed + diff <= bricks) {
                totalBricksUsed += diff;
                bricksUsed.push(diff);
            } else if (ladders > 0) {
                if (!bricksUsed.empty() && bricksUsed.top() > diff) {   // Alert: Corner case ** 
                    totalBricksUsed = totalBricksUsed - bricksUsed.top() + diff;
                    bricksUsed.pop();
                    bricksUsed.push(diff); // Thanks to @amanda_86
                }
                ladders--;
            } 
            else break;
        }
        return reach;
    }
};