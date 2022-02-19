class Solution {
public:
    bool isValid(int n)
    {
        if(n==3 || n==4 || n==7)
            return false;
        
        return true;
    }
    int rotateNumber(int n)
    {
        if(n==1 || n==0 || n==8)
            return n;
        else if(n==2)
            return 5;
        else if(n==5)
            return 2;
        else if(n==9)
            return 6;
        else if(n==6)
            return 9;
        
        return n;
    }
    int rotatedDigits(int n) {
        
        int res=0;
        
        for(int i=1;i<=n;i++)
        {
            int num=i;
            int newNum=0;
            int counter=0;
            bool containdInvalid=false;
            while(num!=0)
            {
                int x=num%10;
                if(!isValid(x))
                {
                    containdInvalid=true;
                    break;
                }
                else
                {
                    newNum+=rotateNumber(x)*pow(10,counter++);
                    num=num/10;
                }
            }
            
            if(!containdInvalid && i!=newNum)
                res++;
        }
        
        return res;
    }
};