class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int> nums2;
        
        for(int i=0;i<nums.size();i++)
        {
            bool isUnique=true;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                    {isUnique=false; break;}
            } 
            if(isUnique)
            {
                nums2.push_back(nums[i]);
            }
        }
        nums=nums2;
        return nums.size();
    }
};