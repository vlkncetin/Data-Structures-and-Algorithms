class Solution {
public:
    double myPow(double x, int n) {
        long longn = n;
        if (longn==0)
            return 1;
        else if(longn < 0)
        {
            longn *=-1;
            x = 1/x;
        }
        
        if(longn%2==0)
            return myPow(x*x, longn/2);
        return myPow(x*x, longn/2)*x;
    }
};