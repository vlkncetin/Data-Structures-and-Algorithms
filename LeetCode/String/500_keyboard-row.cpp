class Solution {
public:
    vector<string> findWords(vector<string>& words) {
     
        string row1="qwertyuiopQWERTYUIOP";
        string row2="asdfghjklASDFGHJKL";
        string row3="zxcvbnmZXCVBNM";
        
        for(int i=words.size()-1;i>=0;i--)
        {
            bool isAllRow1=true;
            bool isAllRow2=true;
            bool isAllRow3=true;
            
            for(int j=0;j<words[i].size();j++)
            {
                size_t found1=row1.find(words[i][j]);
                if(found1==string::npos)
                {
                    isAllRow1=false;
                    break;
                }
            }
            if(!isAllRow1)
            {
                for(int j=0;j<words[i].size();j++)
                {
                    size_t found2=row2.find(words[i][j]);
                    if(found2==string::npos)
                    {
                        isAllRow2=false;
                        break;
                    }
                }
                if(!isAllRow2)
                {
                    for(int j=0;j<words[i].size();j++)
                    {
                        size_t found3=row3.find(words[i][j]);
                        if(found3==string::npos)
                        {
                            isAllRow3=false;
                            break;
                        }
                    }
                }
            }
            
            
            if(!isAllRow1 && !isAllRow2 && !isAllRow3)
                words.erase(words.begin()+i);
        }
        
        
        return words;
        
    }
};