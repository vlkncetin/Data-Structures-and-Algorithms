class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int res=0;
        for(int i=nums.size()-1,j=1;i>=0;i--,j++)
        {
            if(j==k)
            {
                res=nums[i];
                break;
            }
        }
        
        return res;
    }
};