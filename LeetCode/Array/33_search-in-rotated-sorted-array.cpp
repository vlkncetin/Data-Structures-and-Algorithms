class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //sort(nums.begin(),nums.end());
        
        vector<int>::iterator it =find(nums.begin(),nums.end(),target);
        if (it == nums.end())
        {
            return -1;
        }
        return it - nums.begin();
    }
};