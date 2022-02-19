class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                
                if (grid[i][j]==0) 
                    continue;
                
                if ((j > 0 && !grid[i][j-1]) || j == 0) 
                    perimeter++;
                
                if ((i > 0 && !grid[i-1][j]) || i == 0) 
                    perimeter++;
                
                if ((j < columns-1 && !grid[i][j+1]) || j == columns-1) 
                    perimeter++;
                
                if ((i < rows-1 && !grid[i+1][j]) || i == rows-1) 
                    perimeter++;
            }
        }
        
        return perimeter;
    }
};