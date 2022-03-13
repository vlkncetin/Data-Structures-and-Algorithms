class Solution {
public:
    int getPower(int x)
    {
        int res=0;
        if(x==1)
            return res;
        
        while(x!=1)
        {
            res++;
            if(x%2==0)
                x/=2;
            else
                x=x*3+1;
        }
        
        return res;
    }
    int getKth(int lo, int hi, int k) {
        
        vector<int> vec;
        
        for(int i=lo;i<=hi;i++)
            vec.push_back(i);
        
        sort(vec.begin(),vec.end(), [&](const int &a,const int &b)
             {
                 int pow1=getPower(a);
                 int pow2=getPower(b);
                 if(pow1==pow2)
                     return a<b;
                 return pow1<pow2;
             });
        
        return vec[k-1];
    }
};