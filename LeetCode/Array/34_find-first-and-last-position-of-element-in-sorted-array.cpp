class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        
        bool isFirstFound=false;
        for(int i=0;i<nums.size();i++)
        {
            if(target==nums[i])
            {
                if(!isFirstFound)
                {
                   res[0]=i; 
                   isFirstFound=true;
                }
                else
                {
                   res[1]=i; 
                }
            }
        }
        
        if(res[0]!=-1 && res[1]==-1)
            res[1]=res[0];
        
        return res;
    }
};