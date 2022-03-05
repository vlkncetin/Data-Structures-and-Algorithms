class Solution {
public:
    int numberOfSteps(int num) {
        
        int step=0;
        
        while(num!=0)
        {
            step++;
            
            if(num%2==1)
            {
                num--;
            }
            else
            {
                num=num>>1;
            }
        }
        
        return step;
    }
};