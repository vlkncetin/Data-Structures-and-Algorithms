class Solution {
public:
    int mySqrt(int x) {
        
        
        for(long long int i=0;i<INT_MAX;i++)
        {
            if(i*i==(long long)x)
                return i;
            else if(i*i>(long long)x)
                return i-1;
        }
        
        return 0;
    }
};