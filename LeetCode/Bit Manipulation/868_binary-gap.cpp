class Solution {
public:
    int binaryGap(int n) {
        
        vector<int> bits;
        
        while(n!=0)
        {
            if(n%2==0)
                bits.push_back(0);
            else
                bits.push_back(1);
            
            n/=2;
        }
        
        while(bits[0]==0)
        {
            bits.erase(bits.begin());
        }
        
        while(bits[bits.size()-1]==0)
        {
            bits.erase(bits.begin()+bits.size()-1);
        }
        
        if(bits.size()<2)
            return 0;
        
        int maxx=0,iter=0;
        
        for(int i=0;i<bits.size();i++)
        {
            
            if(bits[i]==1)
            {
                maxx=max(maxx,++iter);
                iter=0;
            }
            else
            {
                iter++;
            }
            
        }
        
        return maxx;
    }
};