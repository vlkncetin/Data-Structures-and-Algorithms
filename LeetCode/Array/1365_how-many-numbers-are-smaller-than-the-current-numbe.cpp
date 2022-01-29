class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        unordered_map<int, int> mapResult;
        vector<int> new_nums(nums);

        sort(new_nums.begin(), new_nums.end());

        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            mapResult[new_nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) 
        {
            nums[i] = mapResult[nums[i]];
        }
        
        return nums;
    }
};