class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        if(sentence.size()<26)
            return false;
        
        vector<int> pangram(26,0);
        
        for(int i=0;i<sentence.size();i++)
        {
            pangram[(int)sentence[i]-97]=1;
        }
        
        for(auto x:pangram)
        {
            if(x==0)
                return false;
        }
        
        return true;
    }
};