class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        int result=0;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)
                    continue;
                
                stringstream ss;
                ss<<nums[i]<<nums[j];
                if(target==ss.str())
                    result++;
            }
        }
        
        return result;
    }
};