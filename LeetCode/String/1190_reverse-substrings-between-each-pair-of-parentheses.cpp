class Solution {
public:
    string reverseString(string s)
    {
        string rs="";
        
        for(int i=s.size()-1;i>=0;i--)
        {
            rs.push_back(s[i]);
        }
        
        return rs;
    }
    string reverseParentheses(string s) {
                
        while(1)
        {
            size_t found=s.find("(");
            if(found==string::npos)
                break;
            
            int pOpenPos=0;
            string subString="";
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='(')
                {
                    pOpenPos=i;
                    subString="";
                }
                else if(s[i]==')')
                {
                    string temp="";
                    string first=s.substr(0,pOpenPos);
                    string last=s.substr(i+1,s.size()-i);
                    
                    temp.append(first).append(reverseString(subString)).append(last);
                    s=temp;
                    subString="";
                    break;
                }
                else
                {
                    subString.push_back(s[i]);
                }
            }
        }
        
        return s;
    }
};