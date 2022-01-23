class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> res;
        
        for(int i=0;i<queries.size();i++)
        {
            int xCenter=queries[i][0];
            int yCenter=queries[i][1];
            int radius=queries[i][2];
            
            int counter=0;
            
            for(int j=0;j<points.size();j++)
            {
                int x=points[j][0];
                int y=points[j][1];
                
                if(((x-xCenter)*(x-xCenter)+(y-yCenter)*(y-yCenter))<=(radius*radius))
                    counter++;
            }
            
            res.push_back(counter);
            
        }
        
        return res;
    }
};