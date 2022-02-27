class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        bool isBigger10=false;
        int numIndex=num.size()-1;
        while(k!=0)
        {
            int x=k%10;
            
            if(numIndex<0)
            {
                if(isBigger10)
                {
                    x++;
                }
                num.insert(num.begin(),x%10);
                if(x>9)
                    isBigger10=true;
                else
                    isBigger10=false;
            }
            else
            {
                int sum=x+num[numIndex];
                
                if(isBigger10)
                {
                    sum++;
                }
                num[numIndex]=sum%10;
                if(sum>9)
                    isBigger10=true;
                else
                    isBigger10=false;
            }
            
            numIndex--;
            k/=10;
        }
        if(isBigger10 && numIndex==0)
        {
            int x=num[0];
                
            if(isBigger10)
            {
                x++;
            }
            num[0]=x%10;
            if(x>9)
                isBigger10=true;
            else
                isBigger10=false;
            if(isBigger10)
                num.insert(num.begin(),1);
        }
        if(isBigger10 && numIndex<0)
            num.insert(num.begin(),1);
        if(isBigger10 && numIndex>0)
        {
            while(numIndex>=0)
            {
                int x=num[numIndex];
                
                if(isBigger10)
                {
                    x++;
                }
                num[numIndex]=x%10;
                if(x>9)
                    isBigger10=true;
                else
                    isBigger10=false;
                numIndex--;
            }
            if(isBigger10)
                num.insert(num.begin(),1);
        }
        
        return num;
    }
};