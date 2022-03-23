class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        map<int,map<char,int>> rows,cols,grids;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                        rows[i][board[i][j]]++;
                        cols[j][board[i][j]]++;
                        grids[(i/3)*3+(j/3)][board[i][j]]++;
                        if(rows[i][board[i][j]]>1 || cols[j][board[i][j]]>1 || grids[(i/3)*3+(j/3)][board[i][j]]>1)
                            return false;
                }
            }
        }
        return true;
        
    }
};