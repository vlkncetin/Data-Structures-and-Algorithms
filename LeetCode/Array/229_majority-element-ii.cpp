class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int> mapNum;
        for(int i=0;i<nums.size();i++)
        {
            mapNum[nums[i]]++;
        }
        
        double val=(double)nums.size()/3.0;
        
        vector<int> res;
        for(auto m:mapNum)
        {
            if((double)m.second>val)
                res.push_back(m.first);
        }
        
        return res;
    }
};