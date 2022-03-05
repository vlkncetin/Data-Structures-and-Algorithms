class Solution {
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        for(int i=0;i<nums.size();i++)
        {
            m_IndexMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        
        if(m_IndexMap[target].size()==1)
            return m_IndexMap[target][0];
        
        int x=rand()%m_IndexMap[target].size();
        return m_IndexMap[target][x];
            
    }
    
private:
    unordered_map<int,vector<int>> m_IndexMap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */