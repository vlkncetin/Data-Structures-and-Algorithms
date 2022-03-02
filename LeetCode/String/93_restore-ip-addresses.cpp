class Solution 
{
public:
    bool isValid(string s)
    {
        if(s.length()>3)
        {
            return false;
        }
        if(s[0]=='0' && s.length()>1)
        {
            return false;
        }
        
        int n=stoi(s);
        
        if(n>=0 && n<=255)
            return true;
        return false;  
    }
    
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        
        for(int i=1;i<=3;i++)
        {
            string first=s.substr(0,i);
            
            if(isValid(first))
            {
                for(int j=1;j<=3 && i+j<s.length();j++)
                {
                    string second=s.substr(i,j);
                    
                    if(isValid(second))
                    {
                        for(int k=1;k<=3 && i+j+k<s.length();k++)
                        {
                            string third=s.substr(i+j,k);
                            string fourth=s.substr(i+j+k);
                            
                            if(isValid(third) && isValid(fourth))
                            {
                                res.push_back(first+"."+second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};