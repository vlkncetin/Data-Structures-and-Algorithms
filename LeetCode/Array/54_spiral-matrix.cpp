class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        
        while(!matrix.empty())
        {
            //first, move first row
            for(int i=0;i<matrix[0].size();i++)
            {
                res.push_back(matrix[0][i]);
            }
            if(!matrix.empty())
                matrix.erase(matrix.begin());
                  
            if(matrix.empty())
                break;
         
            //second, move last elements of all rows
            for(int i=0;i<matrix.size();i++)
            {
                res.push_back(matrix[i][matrix[i].size()-1]);
                matrix[i].erase(matrix[i].begin()+matrix[i].size()-1);
            }
            for(int i=matrix.size()-1;i>=0;i--)
            {
                if(matrix[i].empty())
                    matrix.erase(matrix.begin()+i);
            }
            
            if(matrix.empty())
                break;
         
            //third, move last row in reversed order
            for(int i=matrix[matrix.size()-1].size()-1;i>=0;i--)
            {
                res.push_back(matrix[matrix.size()-1][i]);
            }
            if(!matrix.empty())
                matrix.erase(matrix.begin()+matrix.size()-1);
                
            if(matrix.empty())
                break;
         
            //finally, move first elements of all rows
            for(int i=matrix.size()-1;i>=0;i--)
            {
                res.push_back(matrix[i][0]);
                matrix[i].erase(matrix[i].begin());
            }
            for(int i=matrix.size()-1;i>=0;i--)
            {
                if(matrix[i].empty())
                    matrix.erase(matrix.begin()+i);
            }
        }
        
        return res;
    }
};