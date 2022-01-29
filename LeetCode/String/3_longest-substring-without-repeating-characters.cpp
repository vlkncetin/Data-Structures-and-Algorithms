class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            int subcount=1;
            string s2="";
            s2.push_back(s[i]);
            for(int j=i+1;j<s.size();j++)
            {
                size_t index=s2.find(s[j]);
                if(index==string::npos)
                {
                    s2.push_back(s[j]);
                    subcount++;
                }
                else break;
            }
            
            if(subcount>count)
                count=subcount;
        }
        
        return count;
    }
};