class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int ruleIndex=0;
        if(ruleKey=="color")
            ruleIndex=1;
        else if(ruleKey=="name")
            ruleIndex=2;
        
        int res=0;
        for(int i=0;i<items.size();i++)
        {
            if(items[i][ruleIndex]==ruleValue)
                res++;
        }
        
        return res;
    }
};