class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int num=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[i])
                    num++;
            }
        }
        
        return num;
    }
};