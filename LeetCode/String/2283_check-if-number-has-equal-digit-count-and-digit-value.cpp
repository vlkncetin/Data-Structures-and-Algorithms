class Solution {
public:
    bool digitCount(string num) {
        
        map<int,int> mymap;
        
        for(int i=0;i<num.size();i++)
        {
            mymap[num[i]-'0']++;
        }
        
        bool res=true;
        
        for(int i=0;i<num.size();i++)
        {
            if((num[i]-'0')!=mymap[i])
            {
                res=false;
                break;
            }
        }
        
        return res;
    }
};