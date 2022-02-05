class Solution {
public:
    string convertPattern(string pattern)
    {
        string s="";
        
        for(int i=0;i<pattern.size();i++)
        {
            size_t found=pattern.find(pattern[i]);
            stringstream ss;
            ss<<s<<found;
            s=ss.str();
        }
        
        return s;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        pattern = convertPattern(pattern);
        
        for(int i=0;i<words.size();i++)
        {
            if(pattern==convertPattern(words[i]))
            {
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
};