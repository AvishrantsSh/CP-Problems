class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0 ; i < nums.size(); i++){
            int toFind = target - nums[i];
            if (hash.find(toFind) != hash.end())
                return {hash[toFind], i};
            
            hash[nums[i]] = i;
        }
        return {};
    }
};