class Solution {
public:
    bool isValid(string s) {
        
        bool isValid=true;
        
        stack<char> parStack;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                parStack.push(s[i]);
            else if(s[i] == ')' )
            {
                if(parStack.empty() || parStack.top() != '(')
                    return false;
                
                parStack.pop();
            }
            else if(s[i] == '}')
            {
                if(parStack.empty() || parStack.top() != '{')
                    return false;
                
                parStack.pop();
            }
            else if(s[i] == ']')
            {
                if(parStack.empty() || parStack.top() != '[')
                    return false;
                
                parStack.pop();
            }
        }
        
        return parStack.empty();
    }
};