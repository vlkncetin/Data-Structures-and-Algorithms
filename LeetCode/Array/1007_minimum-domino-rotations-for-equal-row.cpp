class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        vector<int> temp1=tops;
        vector<int> temp2=bottoms;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1[0]==temp1[temp1.size()-1])
            return 0;
        if(temp2[0]==temp2[temp2.size()-1])
            return 0;
        
        unordered_map<int,int> topTried;
        unordered_map<int,int> bottomTried;
        for(int i=1;i<=6;i++)
        {
            topTried[i]=INT_MAX;
            bottomTried[i]=INT_MAX;
        }
        int minTriesForTop=INT_MAX;
        int minTriesForBottom=INT_MAX;
        int n=tops.size();
        
        for(int i=0;i<n;i++)
        {
            if(topTried[tops[i]]==INT_MAX)
            {
                topTried[tops[i]]=0;
                
                for(int j=0;j<n;j++)
                {
                    if(i==j || tops[j]==tops[i] && topTried[tops[i]]!=INT_MAX)
                        continue;
                    if(bottoms[j]==tops[i])
                        topTried[tops[i]]++;
                    else
                    {
                        topTried[tops[i]]=INT_MAX;
                        break;
                    }
                }
            }
            if(bottomTried[bottoms[i]]==INT_MAX)
            {  
                bottomTried[bottoms[i]]=0;
                for(int j=0;j<n;j++)
                {
                    if(i==j || bottoms[j]==bottoms[i])
                        continue;
                    if(tops[j]==bottoms[i] && bottomTried[bottoms[i]]!=INT_MAX)
                        bottomTried[bottoms[i]]++;
                    else
                    {
                        bottomTried[bottoms[i]]=INT_MAX;
                        break;
                    }
                }
            }
        }
        
        int res=INT_MAX;
        for(auto x:topTried)
        {
            if(x.second>=0)
                res=min(res,x.second);
        }
        for(auto x:bottomTried)
        {
            if(x.second>=0)
                res=min(res,x.second);
        }
        
        if(res==INT_MAX)
            return -1;
        return res;
    }
};