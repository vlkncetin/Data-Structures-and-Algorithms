class Solution {
public:
    vector<int> partitionLabels(string s) {
                
        map<char, int> charMap;
        
        for(int i = 0; i < s.size(); i++)
        {
            charMap[s[i]] = i;
        }
        
        vector<int> result;
        
        for(int i=0,j=0; i<s.size(); i++)
        {
            j = max(j, charMap[s[i]]);
            if(i == j)
            {
                int totalPrevLen=0;
                for(int x=0; x<result.size(); x++)
                {
                    totalPrevLen+=result[x];
                }
                result.push_back(i-totalPrevLen+1);
            }
        }
        return result;
    }
};