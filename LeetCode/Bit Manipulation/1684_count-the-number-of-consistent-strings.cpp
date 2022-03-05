class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int res=0;
        
        for(int i=0;i<words.size();i++)
        {
            bool isAllowed=true;
            
            for(int j=0;j<words[i].size();j++)
            {
                size_t found=allowed.find(words[i][j]);
                
                if(found==string::npos)
                {
                    isAllowed=false;
                    break;
                }
            }
            
            if(isAllowed)
                res++;
        }
        
        return res;
    }
};