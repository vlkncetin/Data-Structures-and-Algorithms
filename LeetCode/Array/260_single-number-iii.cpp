class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> res;
        
        if(nums.size()==2)
            return nums;
        
        sort(nums.begin(),nums.end());
        
        int counter=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(i==1)
            {
                if(nums[0]!=nums[1])
                    res.push_back(nums[0]);
            }
            if((nums[i]!=nums[i+1])&&(nums[i]!=nums[i-1]))
            {
                counter++;
                res.push_back(nums[i]);
            }
            if(counter==2)
            {
                break;
            }
        }
        
        if(res.size()==1)
            res.push_back(nums[nums.size()-1]);
        
        return res;
    }
};