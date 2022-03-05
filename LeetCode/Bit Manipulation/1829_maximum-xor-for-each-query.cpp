class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> xorrVec;
        int xorr=0;
        
        for(int i=0;i<nums.size();i++)
        {
            xorr ^= nums[i];
            xorrVec.push_back(xorr);
        }
        
        int k=pow(2, maximumBit)-1;
        vector<int> res;
        for(int i=xorrVec.size()-1; i>=0; i--)
        {
            res.push_back(xorrVec[i]^k);
        }
        
        return res;
    }
};