class Solution {
public:
    int convertSingleSymbol(char c)
    {
        if(c=='I')
            return 1;
        else if(c=='V')
            return 5;
        else if(c=='X')
            return 10;
        else if(c=='L')
            return 50;
        else if(c=='C')
            return 100;
        else if(c=='D')
            return 500;
        else if(c=='M')
            return 1000;
        
        return 1;
    }
    int romanToInt(string s) {
        
        int num=convertSingleSymbol(s[s.size()-1]);
        int biggest=convertSingleSymbol(s[s.size()-1]); //to understand increasing or decresing like IX or XI
        
        for(int i=s.size()-2;i>=0;i--)
        {
            int currentNum=convertSingleSymbol(s[i]);
            if(currentNum<biggest)
            {
                num-=currentNum;
            }
            else
            {
                biggest=currentNum;
                num+=currentNum;
            }     
        }
        
        return num;
    }
};