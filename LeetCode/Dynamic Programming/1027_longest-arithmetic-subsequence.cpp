class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int result=2;
        vector<vector<int>> dp(nums.size(),vector<int>(1001,1));
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j] + 500;
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                
                result=max(result,dp[i][diff]);
                
            }
        }
        return result;
    }
};