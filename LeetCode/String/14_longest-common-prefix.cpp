class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int totalstr=strs.size();
        if(totalstr==1) return strs[0];
        string common="";
        for(int i=0;i<strs[0].size();i++)
        {
            bool isSame=false;
            for(int j=1;j<strs.size();j++)
            {
                if(i>=strs[j].size()) {isSame=false; break;}
                if(strs[0][i]==strs[j][i])
                {
                    isSame=true;
                    
                }else {isSame=false; break;}
            }
            if(isSame)
                common.push_back(strs[0][i]);
            else break;
        }
        return common;
    }
};