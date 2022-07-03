class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int,int> numMap;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            numMap[nums[i]]++;
            
            if(numMap[nums[i]]==2)
                res.push_back(nums[i]);
        }
        
        return res;
    }
};