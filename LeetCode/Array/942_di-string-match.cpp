class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        vector<int> res;
                
        int smallest=0;
        int largest=s.size();
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='I')
            {
                res.push_back(smallest);
                smallest++;
            }
            else if(s[i]=='D')
            {
                res.push_back(largest);
                largest--;
            }
        }
        
        res.push_back(largest);
                
        return res;
    }
};