class Solution {
public:
    int balancedStringSplit(string s) {
        
        int numL=0,numR=0, total=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='L')
            {
                numL++;
                if(numL==numR)
                {
                    numL=0;
                    numR=0;
                    total++;
                }
            }
            else
            {
                numR++;
                if(numL==numR)
                {
                    numL=0;
                    numR=0;
                    total++;
                }
            }
        }
        
        return total;
    }
};