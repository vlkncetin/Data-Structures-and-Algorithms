class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int result=0;
        int last=-1;
        
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)
            {
                if(last<0) //beginning seats
                    result=i;
                else //middle seats
                    result=max(result,(i-last)/2);
                
                last=i;
            }
        }
        
        int fromEnd=seats.size()-last-1; //end seats
        result=std::max(result,fromEnd);
        
        return result;
    }
};