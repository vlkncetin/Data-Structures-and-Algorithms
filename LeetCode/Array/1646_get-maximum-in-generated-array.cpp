class Solution {
public:
    int getMaximumGenerated(int n) {
        
        vector<int> res(n+1);
        
        res[0]=0;
        if(n==0)
            return 0;
        res[1]=1;
        int maxx=1;
        
        for(int i=2;i<res.size();i++)
        {
            if(i%2==0)
            {
                res[i]=res[i/2];
            }
            else
            {
                res[i]=res[i/2]+res[i/2+1];
            }
            maxx=max(maxx,res[i]);
        }
        
        return maxx;
    }
};