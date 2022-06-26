class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> mymap;
        
        for(int i=0;i<arr.size();i++)
        {
            mymap[arr[i]]++;
        }
        
        vector<int> occurences;
        
        for(auto i=mymap.begin();i!=mymap.end();i++)
        {
            vector<int>::iterator it;
            it = find(occurences.begin(),occurences.end(),i->second);
            
            if(it!=occurences.end())
                return false;
            
            occurences.push_back(i->second);
        }
        
        return true;
    }
};