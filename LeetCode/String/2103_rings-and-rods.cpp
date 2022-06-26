class Solution {
public:
    int countPoints(string rings) {
     
        unordered_map<char,vector<char>> colors_in_rods;
        
        for(int i=0;i<rings.size()-1;i+=2)
        {
            std::vector<char>::iterator it;
            it=find(colors_in_rods[rings[i+1]].begin(),colors_in_rods[rings[i+1]].end(),rings[i]);
            
            if(it==colors_in_rods[rings[i+1]].end())
            {
                colors_in_rods[rings[i+1]].push_back(rings[i]);
            }
        }
        
        int res=0;
        
        for(auto i=colors_in_rods.begin();i!=colors_in_rods.end();i++)
        {
            if(i->second.size()==3)
                res++;
        }
        
        return res;
    }
};