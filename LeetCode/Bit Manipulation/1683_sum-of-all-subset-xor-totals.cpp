class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int res = 0;
        int n=nums.size();
        
        for (int i = 1; i < pow(2,n); i++)
        {
            int totalOfSet = 0;
            
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    totalOfSet ^= nums[j];
            }
               
            res += totalOfSet;
        }
        
        return res;
    }
};

