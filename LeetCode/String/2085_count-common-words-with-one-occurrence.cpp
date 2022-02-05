class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        int count=0;
        map<string,int> map1;
        map<string,int> map2;
        
        for(int i=0;i<words1.size();i++)
        {
            map1[words1[i]]++;
        }
        
        for(int i=0;i<words2.size();i++)
        {
            map2[words2[i]]++;
        }
        
        for(auto m : map1)
        {
            if(m.second==1 && map2[m.first]==1)
                count++;
        }
            
        return count;
    }
};