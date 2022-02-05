class Solution {
public:
    int secondHighest(string s) {
        
        vector<int> nums;
        int max=-1;
        int secondmax=-1;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0' >=0 && s[i]-'0'<=9)
            {
                if(s[i]-'0'>max && max==-1)
                {
                    max=s[i]-'0';
                }
                else if(s[i]-'0'>max)
                {
                    secondmax=max;
                    max=s[i]-'0';
                }
                else if(max>s[i]-'0' && s[i]-'0'>secondmax)
                {
                    secondmax=s[i]-'0';
                }
            }
        }
            
        return secondmax;
    }
};