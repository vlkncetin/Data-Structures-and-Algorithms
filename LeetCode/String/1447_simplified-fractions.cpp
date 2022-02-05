class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        
        vector<string> res;
        
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i==1)
                {
                    stringstream ss;
                    ss<<i<<"/"<<j;
                    res.push_back(ss.str());
                }
                else
                {
                    if(gcd(i,j)!=1)
                        continue;
                    else
                    {
                       stringstream ss;
                        ss<<i<<"/"<<j;
                        res.push_back(ss.str()); 
                    }
                }
            }
        }
        
        return res;
    }
};