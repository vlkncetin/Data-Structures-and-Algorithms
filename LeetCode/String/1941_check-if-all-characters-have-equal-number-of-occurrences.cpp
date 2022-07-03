class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        unordered_map<char,int> charCount;
        
        for(int i=0;i<s.size();i++)
        {
            charCount[s[i]]++;
        }
                
        int len=charCount[s[0]];
        
        for(auto i=charCount.begin();i!=charCount.end();i++)
        {
            if(i->second!=len)
                return false;
        }
        
        return true;
    }
};