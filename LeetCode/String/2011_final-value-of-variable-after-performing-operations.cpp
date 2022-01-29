class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int res=0;
        
        for(int i=0;i<operations.size();i++)
        {
            size_t foundNeg=operations[i].find("--");
            
            if(foundNeg!=string::npos)
            {
                res--;
            }
            else
            {
                res++;
            }
        }
        
        return res;
    }
};