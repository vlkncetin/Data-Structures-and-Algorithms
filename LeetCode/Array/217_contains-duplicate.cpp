class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        auto it = std::unique( nums.begin(), nums.end() );
        bool wasUnique = (it == nums.end() );
        return !wasUnique;
    }
};