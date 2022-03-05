class Solution {
public:
    struct {
        int numberOfOnes(int a)
        {
            if(a==0)
                return 0;
            if(a==1)
                return 1;
            int num=0;
            while(a!=1)
            {
                if(a%2!=0)
                {
                    num++;
                    a--;
                }
                else
                {
                    a/=2;
                }
            }
            return ++num;
        }
        bool operator()(int a, int b) 
        { 
            int aa=numberOfOnes(a);
            int bb=numberOfOnes(b);
            if(aa>bb)
                return false;
            if(aa<bb)
                return true;
            if(aa==bb)
            {
                if(a<b)
                    return true;
                else
                    return false;
            }
            return false;
        }
    } customLess;
    
    int numberOfOnes(int a)
        {
            if(a==0)
                return 0;
            if(a==1)
                return 1;
            int num=0;
            while(a!=1)
            {
                if(a%2!=0)
                {
                    num++;
                    a--;
                }
                else
                {
                    a/=2;
                }
            }
            return ++num;
        }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),customLess);
        
        
        return arr;
    }
};