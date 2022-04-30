// Approach - 1 (Deleting Elements within Array)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0, ref = nums[0], i = 1;
        for(i = 1; i < nums.size(); i++){
            if (nums[i] == ref)
                continue;
            nums[ptr++] = ref;
            ref = nums[i];
        }
        nums[ptr] = ref;
        return ptr+1;
    }
};

// Approach - 2 (Using less variables)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 1; i < n; i++){
            if (nums[i] == nums[i-1])
                count ++;
            else
                nums[i-count] = nums[i];
        }
        return n - count;
    }
};