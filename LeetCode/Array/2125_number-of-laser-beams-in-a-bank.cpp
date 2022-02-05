class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int numOfBeams=0;
        vector<int> deviceCount;
        
        for(int i=0;i<bank.size();i++)
        {
            int numOfOnes=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                    numOfOnes++;
            }
            
            if(numOfOnes>0)
                deviceCount.push_back(numOfOnes);
        }
        
        if(deviceCount.size()==0)
            return 0;
        
        for(int i=0;i<deviceCount.size()-1;i++)
        {
            numOfBeams+=deviceCount[i]*deviceCount[i+1];
        }
        
        return numOfBeams;
    }
};