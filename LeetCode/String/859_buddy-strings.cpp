class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size())
            return false;
        
        
        bool isResult=true;
        int counter=0;
        int firstDiffCharIndex=-1,secondDiffCharIndex=-1;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                counter++;
                if(counter==3)
                    return false;
                if(counter==1)
                    firstDiffCharIndex=i;
                else if(counter==2)
                    secondDiffCharIndex=i;
            }
        }
        if(counter==1)
            return false;
        cout<<counter<< " "<<firstDiffCharIndex<<" "<<secondDiffCharIndex<<endl;
        
        if(counter==0)
        {
            unordered_map<char,int> charCount;
            for(int i=0;i<s.size();i++)
            {
                charCount[s[i]]++;
            }
            for(auto m:charCount)
            {
                if(m.second>1)
                    return true;
            }
        }
        else if(s[firstDiffCharIndex]==goal[secondDiffCharIndex] && goal[firstDiffCharIndex]==s[secondDiffCharIndex])
            return true;
        
        return false;
    }
};