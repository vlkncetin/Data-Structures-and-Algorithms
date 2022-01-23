class Solution {
public:
    bool isIncreasing(vector<int> nums)
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1])
                return false;
        }
        
        return true;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        
        if(isIncreasing(nums))
            return true;
        
        if(nums.size()<3)
            return true;
        
        for(int i=0;i<nums.size();i++)
        {
            vector<int> newVec=nums;
            newVec.erase(newVec.begin()+i);
            if(isIncreasing(newVec))
                return true;
        }
        
        return false;
    }
};