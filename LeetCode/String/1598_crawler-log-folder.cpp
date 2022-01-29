class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int stepToMain=0;
        
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../")
            {
                stepToMain=max(stepToMain-1,0);
            }
            else if(logs[i]=="./")
            {
                continue;
            }
            else
            {
                stepToMain++;
            }
        }
        
        return stepToMain;
    }
};