class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deqq;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++)
        {
            while(!deqq.empty() && i-deqq.front()>=k)
                deqq.pop_front();
            
            while(!deqq.empty() && nums[deqq.back()] < nums[i])
                deqq.pop_back();
            
            deqq.push_back(i);
            if(i>=k-1)
                res.push_back(nums[deqq.front()]);
        }
        return res;
    }
};