class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int uniqueMails=0;
        unordered_map<string,set<string>> allMails;
        
        for(int i=0;i<emails.size();i++)
        {
            size_t found=emails[i].find("@");
            string local=emails[i].substr(0, found);
            string domain=emails[i].substr(found+1, emails[i].size()-found-1);
            
            string regulatedLocal=local;
            found=regulatedLocal.find("+");
            regulatedLocal=regulatedLocal.substr(0, found);
            
            while(true)
            {
                found=regulatedLocal.find(".");
                if(found==string::npos)
                {
                    break;
                }
                else
                {
                    regulatedLocal.erase(regulatedLocal.begin()+found);
                }
            }
            
            allMails[domain].insert(regulatedLocal);
        }
        
        for(auto m : allMails)
            uniqueMails+=m.second.size();
        
        return uniqueMails;
    }
};