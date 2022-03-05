class Solution {
public:
    Solution(vector<int>& nums) {
        m_orig=nums;
        m_shuff=nums;
        srand(time(0));
    }
    
    vector<int> reset() {
        m_shuff=m_orig;
        return m_orig;
    }
    
    vector<int> shuffle() {
        
        for (int i=0;i<m_shuff.size();i++)
        {
            int pos = rand()%(m_shuff.size()-i);
            swap(m_shuff[i+pos], m_shuff[i]);
        }
        return m_shuff;
    }
    
private:
    vector<int> m_orig;
    vector<int> m_shuff;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */