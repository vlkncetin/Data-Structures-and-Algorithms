class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans;
        vector<int> newVec(nums.begin()+nums.size()/2, nums.end());
        
        for(int i=0;i<nums.size()/2;i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(newVec[i]);
        }
        
        return ans;
    }
};