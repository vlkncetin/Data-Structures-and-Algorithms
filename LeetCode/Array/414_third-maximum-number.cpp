class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int size=nums.size();
        sort(nums.begin(),nums.end());

        if(size <= 2)
           return nums[size-1];
        
        int count = 0;

        for(int i=size-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                if(++count == 2)
                {
                    return nums[i-1];
                }
            }
            
        }
        return nums[size-1];
    }
};