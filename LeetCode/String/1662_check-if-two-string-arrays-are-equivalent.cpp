class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string fullword1="";
        string fullword2="";
        
        for(int i=0;i<word1.size();i++)
        {
            fullword1=fullword1.append(word1[i]);
        }
        
        for(int i=0;i<word2.size();i++)
        {
            fullword2=fullword2.append(word2[i]);
        }
        
        if(fullword2==fullword1)
            return true;
        
        return false;
    }
};