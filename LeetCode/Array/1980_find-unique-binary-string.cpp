class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        vector<int> numint;
        
        for(int i=0; i<nums.size(); i++)
        {
            int num=0;
            for(int j=nums[i].size()-1,k=0; j>=0; j--,k++)
            {
                num+=pow(2,k)*(nums[i][j]-'0');
            }
            numint.push_back(num);
        }
        
        sort(numint.begin(),numint.end());
        
        int missing=0;
        if(numint[0]!=0)
        {
            string allZero="";
            for(int i=0; i<nums[0].size(); i++)
            {
                allZero.push_back('0');
            }
            return allZero;
        }
        else
        {
            bool isDetected=false;
            for(int i=0; i<numint.size()-1; i++)
            {
                if((numint[i]+1)!=numint[i+1])
                {
                    missing=numint[i]+1;
                    isDetected=true;
                    break;
                }
            }
            
            if(!isDetected)
                missing=numint[numint.size()-1]+1;
        }
        
        string res="";
        while(missing!=0)
        {
            if(missing%2==0)
                res.insert(0,"0");
            else
                res.insert(0,"1");
            missing/=2;
        }
        if(res.size()!=nums[0].size())
        {
            while(res.size()!=nums[0].size())
            {
                res.insert(0,"0");
            }
        }
        
        return res;
    }       
};