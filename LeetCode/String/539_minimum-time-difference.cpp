class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        //convert HH:MM to total minutes from 00:00 i.e. 01:05=65
        vector<int> minutes;
        
        for(int i=0;i<timePoints.size();i++)
        {
            stringstream sshour, ssminute;
            sshour<<timePoints[i].substr(0,2);
            ssminute<<timePoints[i].substr(3,2);
            int hourInt, minuteInt;
            sshour>>hourInt;
            ssminute>>minuteInt;
            
            minutes.push_back(60*hourInt+minuteInt);
        }
        
        int minDiff=INT_MAX;
        
        for(int i=0;i<minutes.size();i++)
        {
            for(int j=i+1;j<minutes.size();j++)
            {
                int diff=min(abs(1440-abs(minutes[i]-minutes[j])), abs(minutes[i]-minutes[j]));
                minDiff=min(minDiff, diff);
                
                if(minDiff==0)
                    return 0;
            }
        }
        
        return minDiff;
    }
};