class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        vector<string> all_destinations;
        unordered_map<string,string> citymap;
        
        for(int i=0;i<paths.size();i++)
        {
            all_destinations.push_back(paths[i][1]);
            citymap[paths[i][0]]=paths[i][1];
        }
        
        string res="";
        
        for(int i=0;i<all_destinations.size();i++)
        {
            bool isResult=true;
            for(auto j=citymap.begin();j!=citymap.end();j++)
            {
                if(all_destinations[i]==j->first)
                {
                    isResult=false;
                    break;
                }
            }
            
            if(isResult)
                res=all_destinations[i];
        }
        
        return res;
    }
};