class Solution {
public:
    string sortSentence(string s) {
        
        map<int, string> sentence;
        string temp="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
                continue;
            
            if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
            {
                sentence[(int)s[i]]=temp;
                temp="";
            }
            else
            {
                temp.push_back(s[i]);
            }
        }
        
        string res="";
        
        for(auto m : sentence)
        {
            res.append(m.second).append(" ");
        }
        
        res.erase(res.begin()+res.size()-1);
        
        return res;
    }
};