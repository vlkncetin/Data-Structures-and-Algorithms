class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        vector<int> xCoords;
        
        for(int i=0;i<points.size();i++)
        {
            xCoords.push_back(points[i][0]);
        }
        
        sort(xCoords.begin(),xCoords.end());
        
        int maxArea=0;
        for(int i=0;i<xCoords.size()-1;i++)
        {
            maxArea=max(maxArea,xCoords[i+1]-xCoords[i]);
        }
        
        return maxArea;
    }
};