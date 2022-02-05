class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int res=0;
        
        int index=s.size()-1;
        bool isWordStarted=false;
        while(index>=0)
        {
            if(isWordStarted && s[index]==' ')
                return res;
            else if(!isWordStarted && s[index]==' ')
            {
                index--;
                continue;
            }
            
            isWordStarted=true;
            res++;
            index--;
        }
        
        return res;
    }
};