class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string> keys;
        
        for(int i=0;i<knowledge.size();i++)
        {
            keys[knowledge[i][0]]=knowledge[i][1];
        }
        
        string newstring="";
        string tempstring="";
        bool isParanthesisStarted=false;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                isParanthesisStarted=true;
            }
            else if(s[i]==')')
            {
                isParanthesisStarted=false;
                stringstream ss;
                if(keys.find(tempstring)==keys.end())
                    ss<<"?";
                else
                    ss<<keys[tempstring];
                newstring=newstring.append(ss.str());
                tempstring="";
            }
            else if(!isParanthesisStarted)
            {
                newstring+=s[i];
            }
            else if(isParanthesisStarted)
            {
                tempstring+=s[i];
            }
            
        }
        
        return newstring;
    }
};