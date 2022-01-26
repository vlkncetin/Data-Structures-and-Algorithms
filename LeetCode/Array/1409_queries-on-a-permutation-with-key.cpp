class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> perm;
        vector<int> res;
        for(int i=0;i<m;i++)
            perm.push_back(i+1);
        
        for(int i=0;i<queries.size();i++)
        {
            int val=queries[i];
            int j=0;
            for(j=0;j<perm.size();j++)
            {
                if(perm[j]==val)
                    break;
            }
            perm.erase(perm.begin()+j);
            perm.insert(perm.begin(),val);
            
            res.push_back(j);
        }
        
        return res;
    }
};