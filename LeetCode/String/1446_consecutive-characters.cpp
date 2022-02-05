class Solution {
public:
    int maxPower(string s) {
        
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        
        int maxpower=1,currentpower=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]==s[i])
            {
                currentpower++;
                maxpower=max(currentpower,maxpower);
            }
            else
                currentpower=1;
        }
        
        return maxpower;
    }
};