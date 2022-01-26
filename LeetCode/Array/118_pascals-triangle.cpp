class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                vector<int> temp{1};
                res.push_back(temp);
                continue;
            }
            
            vector<int> temp{1};
            for(int j=0;j<res[res.size()-1].size()-1;j++)
            {
                temp.push_back(res[res.size()-1][j]+res[res.size()-1][j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        
        return res;
    }
};