class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int modifyCount=0;
        
        if(nums.size()<3)
            return true;
        
        if(nums[0]>nums[1])
        {
            modifyCount++;
            nums[0]=nums[1];
        }
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                modifyCount++;
                if(modifyCount>1)
                    return false;
                if(nums[i-2] <= nums[i]) 
                    nums[i-1] = nums[i];    
                else 
                    nums[i] = nums[i-1];
            }
        }
        
        return true;
    }
};