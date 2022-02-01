class Solution {
public:
    string interpret(string command) {
        
        string res;
        
        for(int i=0;i<command.size();)
        {
            if(command[i]=='G')
            {
                res.push_back('G');
                i++;
            }
            else if(i!=command.size()-1 && command[i]=='(' && command[i+1]==')')
            {
                res.push_back('o');
                i+=2;
            }
            else if(i!=command.size()-1 && command[i]=='(' && command[i+1]=='a')
            {
                res.push_back('a');
                res.push_back('l');
                i+=4;
            }
        }
        
        return res;
    }
};