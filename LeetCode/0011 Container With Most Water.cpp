class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ptr1 = 0, ptr2 = n - 1, maxVol = 0;
        while(ptr1 < ptr2){
            maxVol = max(maxVol, min(height[ptr1], height[ptr2]) * (ptr2-ptr1));
            if(height[ptr1] < height[ptr2])
                ptr1++;
            else if(height[ptr1] > height[ptr2])
                ptr2--;
            else{
                ptr1++;
                ptr2--;
            }
        }
        return maxVol;
    }
};