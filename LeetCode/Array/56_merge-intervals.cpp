class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> merged;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> temp = intervals[0];
        
        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i][0]<=temp[1])
            {
                temp[1]=max(intervals[i][1],temp[1]);
            }
            else
            {
                merged.push_back(temp);
                temp = intervals[i];
            }
        }
        
        merged.push_back(temp);
        
        return merged;
    }
};