class Solution {
public:
    bool isLetter(char c)
    {
        if((c>=65 && c<=90) || (c>=97 && c<=122))
            return true;
        
        return false;
    }
    string reverseOnlyLetters(string s) {
        
        stringstream ss;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(isLetter(s[i]))
                ss<<s[i];
        }
        
        string reversed=ss.str();
        
        for(int i=0,j=0;i<s.size();i++)
        {
            if(isLetter(s[i]))
            {
                s[i]=reversed[j++];
            }
        }
        
        return s;
    }
};