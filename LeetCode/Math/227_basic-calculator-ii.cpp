class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i] == ' ')
                continue;
            else if(isdigit(s[i]))
            {
                string num="";
                while(i<s.size() && isdigit(s[i]))
                {
                    num.push_back(s[i++]);
                }
                stringstream ss;
                ss<<num;
                int numint;
                ss>>numint;
                nums.push(numint);
                i=i-1;
            }
            else // operator
            {
                while(!ops.empty() && precedence(ops.top()) >= precedence(s[i]))
                {
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();

                    int out = applyOp(num1, num2, ops.top());
                    ops.pop();
                    nums.push(out);
                }
                ops.push(s[i]);
            }
        }
        
        while(!ops.empty()) {
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            int out = applyOp(num1, num2, ops.top());
            ops.pop();
            
            nums.push(out);
        }
        
        return nums.top();
    }
    
    int applyOp(int a, int b, char op) {
        int out = 0;
        
        switch(op){ 
            case '+': out = a + b; break;
            case '-': out = a - b; break;
            case '*': out = a * b; break;
            case '/': out = a / b; break;
        }
        return out;
    }
    
    int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        else if (op == '*' || op == '/') return 2;
        else return 0;
    }
};