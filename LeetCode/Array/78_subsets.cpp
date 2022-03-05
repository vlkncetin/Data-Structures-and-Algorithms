class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> nullset;
        res.push_back(nullset);
        
        int n=nums.size();
        
        for(int i=1;i<pow(2,n);i++)
        {
            vector<int> subset;
            for(int j=0;j<n;j++)
            {
                if(i & (1 << j))
                    subset.push_back(nums[j]);
            }
            res.push_back(subset);
        }
        
        return res;
    }
};