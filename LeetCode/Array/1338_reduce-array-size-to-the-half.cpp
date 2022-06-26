class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int arrsize=arr.size();
        map<int,int> mymap;
        
        for(int i=0;i<arrsize;i++)
        {
            mymap[arr[i]]++;
        }
        
        int res=0;
        
        vector<int> occurences;
        for(auto i=mymap.begin();i!=mymap.end();i++)
        {
            occurences.push_back(i->second);
        }
        
        sort(occurences.begin(),occurences.end(),[&](const int &a,const int &b)
             {
                 return a>b;
             });
        
        int sum=0;
        for(int i=0;i<occurences.size();i++)
        {
            sum+=occurences[i];
            res++;
            if((arrsize-sum)<=arrsize/2)
                break;
        }
        
        return res;
    }
};