class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res;
        
        int totalproduct=1;
        int totalproductWithoutZero=1;
        bool isAllZero=true;
        int zeroCount=0;
        for(int i=0;i<nums.size();i++)
        {
            totalproduct*=nums[i];
            if(nums[i]!=0)
            {
                isAllZero=false;
                totalproductWithoutZero*=nums[i];
            }
            else
                zeroCount++;
        }
        
        if(isAllZero)
            return nums;
        
        if(totalproduct!=0)
        {
            for(int i=0;i<nums.size();i++)
            {
                res.push_back(totalproduct/nums[i]);
            }
        }
        else
        {
            if(zeroCount==1)
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]!=0)
                        res.push_back(0);
                    else
                        res.push_back(totalproductWithoutZero);
                }
            else
                for(int i=0;i<nums.size();i++)
                {
                    res.push_back(0);
                }
        }
        
        
        return res;
    }
};