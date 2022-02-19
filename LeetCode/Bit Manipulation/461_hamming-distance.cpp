class Solution {
public:
    string convertToStr(int n)
    {
        string s="";
        
        while(n!=0)
        {
            if(n%2==0)
                s.insert(s.begin(),'0');
            else
                s.insert(s.begin(),'1');
            
            n/=2;
        }
        
        return s;
    }
    int hammingDistance(int x, int y) {
        
        int res=0;
        
        //ensure that x is the smaller one
        if(x>y)
        {
            int temp=x;
            x=y;
            y=temp;
        }
        
        string xStr=convertToStr(x);
        string yStr=convertToStr(y);
        
        while(xStr.size()!=yStr.size())
        {
            xStr.insert(xStr.begin(),'0');
        }
                
        for(int i=0;i<yStr.size();i++)
        {
            if(i<xStr.size() && xStr[i]!=yStr[i])
                res++;
        }
        
        return res;
    }
};