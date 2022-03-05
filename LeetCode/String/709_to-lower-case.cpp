class Solution {
public:
    string toLowerCase(string s) {
        
        //A:65, a:97
        //Z:90, z:122
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c>=65 && c<=90)
                s[i]+=32;
        }
        return s;
    }
};