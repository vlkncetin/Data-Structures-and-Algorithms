class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        for(int layer=0;layer<n/2;layer++)
        {
            int first=layer;
            int last=n-layer-1;
            
            for(int i=first;i<last;i++)
            {
                int offset=i-first;
                //save top
                int top=matrix[first][i];
                
                //left to top
                matrix[first][i]=matrix[last-offset][first];
                
                //bottom to left
                matrix[last-offset][first]=matrix[last][last-offset];
                
                //right to bottom
                matrix[last][last-offset]=matrix[i][last];
                
                //top to right
                matrix[i][last]=top;
            }
        }
    }
};