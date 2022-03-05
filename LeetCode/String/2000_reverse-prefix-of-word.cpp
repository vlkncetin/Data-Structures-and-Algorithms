class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i=0;
        string prefix="",rprefix="";
        for(i=0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                prefix.push_back(word[i]);
                break;
            }
            else
                prefix.push_back(word[i]);
        }
        
        if(prefix==word && word[word.size()-1]!=ch)
            return prefix;
        
        for(int j=prefix.size()-1;j>=0;j--)
        {
            rprefix.push_back(prefix[j]);
        }
        
        stringstream ss;
        ss<<rprefix<<word.substr(i+1,word.size()-i);
        
        return ss.str();
    }
};