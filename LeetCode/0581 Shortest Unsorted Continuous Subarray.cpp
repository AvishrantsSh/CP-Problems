class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int p1 = -1, p2 = -1, big = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(big > nums[i]){
                if(p1 < 0) p1 = i-1;
                while(p1 > 0 && nums[p1 - 1] > nums[i])p1--;
                p2 = i+1;
            }
            else big = nums[i];
        }
        return p2 - p1;
    }
};