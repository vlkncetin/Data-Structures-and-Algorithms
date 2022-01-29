class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> res;
        
        if(words.size()==1)
        {
            for(int i=0;i<words[0].size();i++)
            {
                stringstream ss;
                ss<<words[0][i];
                res.push_back(ss.str());
            }
        }
        else
        {
            for(int i=0;i<words[0].size();i++)
            {
                stringstream ss;
                ss<<words[0][i];
                res.push_back(ss.str());
            }
            
            for(int i=res.size()-1;i>=0;i--)
            {
                bool isAllFound=true;
                for(int j=1;j<words.size();j++)
                {
                    size_t found=words[j].find(res[i]);
                    if(found==string::npos)
                    {
                        isAllFound=false;
                        break;
                    }
                    else
                    {
                        words[j].erase(words[j].begin()+found);    
                    }
                }    
                if(!isAllFound)
                {
                    res.erase(res.begin()+i);
                }
            }
        }
        
        return res;
    }
};