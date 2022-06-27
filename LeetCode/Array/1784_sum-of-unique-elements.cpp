class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        unordered_map<int,int> mymap;
        
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]++;
        }
        
        int sum=0;
        
        for(auto i=mymap.begin();i!=mymap.end();i++)
        {
            if(i->second==1)
                sum+=i->first;
        }
        
        return sum;
    }
};