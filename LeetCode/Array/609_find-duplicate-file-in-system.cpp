class Solution {
public:

    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> result;
        
        unordered_map<string,vector<string>> mapPath;
        
        // parses "root/a 1.txt(abcd) 2.txt(efgh)" as:
        // abcd => root/a/1.txt and efgh => root/a/2.txt
        
        for(int i=0;i<paths.size();i++)
        {
            string path=paths[i];
            //Firstly, find the first space
            string root;
            size_t foundSpace=path.find(" ");
            root=path.substr(0,foundSpace);
            path.erase(0,foundSpace+1);
            while(1)
            {
                size_t found1=path.find("(");
                size_t found2=path.find(")");

                if(found1!=string::npos && found2!=string::npos)
                {
                    //Find content (abcd)
                    string content=path.substr(found1+1,found2-found1-1);
                    path.erase(found1,found2-found1+1);

                    //Find filename 1.txt
                    size_t foundSpace2=path.find(" ");
                    string filename=path.substr(0,foundSpace2);
                    path.erase(0,foundSpace2+1);
                    stringstream ssFullPath;
                    ssFullPath<<root<<"/"<<filename;
                    
                    mapPath[content].push_back(ssFullPath.str());
                }
                else
                    break;
            }
        }
            
        for(auto i = mapPath.begin(); i != mapPath.end(); i++)
        {
            if(i->second.size()>1)
                result.push_back(i->second);
        }
        
        return result;
    }
};