class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int> res;
        
        int missing=nums[nums.size()-1]+1;
        int duplicate=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                duplicate=nums[i];
            }
            
            if(nums[i+1]-nums[i]==2)
            {
                missing=nums[i]+1;
            }
        }
        
        if(nums[0]!=1)
        {
            missing=1;
        }
        
        res.push_back(duplicate);
        res.push_back(missing);
        return res;
    }
};