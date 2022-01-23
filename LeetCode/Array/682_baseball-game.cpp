class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> myVec;
        
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                myVec.pop_back();
            }
            else if(ops[i]=="D")
            {
                int num1;
                stringstream ss1;  
                ss1 << myVec[myVec.size()-1]; 
                ss1 >> num1; 
                myVec.push_back(num1*2);
            }
            else if(ops[i]=="+")
            {
                int num1,num2;
                stringstream ss1,ss2;  
                ss1 << myVec[myVec.size()-1];  
                ss2 << myVec[myVec.size()-2]; 
                ss1 >> num1; 
                ss2 >> num2; 
                myVec.push_back(num1+num2);
            }
            else
            {
                int num1;
                stringstream ss1;  
                ss1 << ops[i]; 
                ss1 >> num1; 
                myVec.push_back(num1);
            }
        }
        
        int sum=0;
        for(int i=0;i<myVec.size();i++)
        {
            sum+=myVec[i];
        }
        return sum;
    }
};