class Solution {
public:
    string convertToTitle(int columnNumber) {
        //A=65, Z=90
        
        string res="";
        
        while(columnNumber!=0)
        {
            columnNumber--;
            int x=columnNumber%26;
            
            res.push_back((char)(x+65));
            columnNumber=columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};