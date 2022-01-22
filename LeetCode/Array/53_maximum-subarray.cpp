class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curMax = 0, maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);
        }
        
        return maxSum;
    }
};