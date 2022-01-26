class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> sumvec;
        sumvec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            sumvec.push_back(sumvec[sumvec.size()-1]+nums[i]);
        }
        
        int last=sumvec[sumvec.size()-1];
        for(int i=0;i<sumvec.size();i++)
        {
            if(i==0)
            {
                if((last-sumvec[0])==0)
                    return i;
            }
            else if((last-sumvec[i])==sumvec[i-1])
                return i;
        }
                
        return -1;
    }
};