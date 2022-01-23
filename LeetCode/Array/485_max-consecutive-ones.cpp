class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxConsecutive=0;
        int curConsecutive=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                curConsecutive++;
                if(curConsecutive>maxConsecutive)
                    maxConsecutive=curConsecutive;
            }
            else
                curConsecutive=0;
        }
        
        return maxConsecutive;
    }
};