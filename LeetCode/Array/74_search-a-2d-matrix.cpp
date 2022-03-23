class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty())
            return false;
        int cols=matrix[0].size();
        int lenght=0;
        int height=cols*matrix.size()-1;
        
        while(lenght<=height)
        {
            int middle=(lenght+height)/2;
            
            if(matrix[middle/cols][middle%cols]==target)
                return true;
            if(matrix[middle/cols][middle%cols]>target) 
                height=middle-1;
            else 
                lenght=middle+1;
        }
        return false;
    }
};