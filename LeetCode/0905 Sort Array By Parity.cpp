class Solution {
public:
    void swap(int &a, int &b){
        if (a == b)
            return;
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] % 2)
                continue;
            
            swap(nums[i], nums[index]);
            index++;
        }
        return nums;
    }
};