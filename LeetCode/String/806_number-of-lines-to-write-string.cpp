class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        
        vector<int> res;
        unordered_map<char,int> newmap;
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<alphabet.size();i++)
        {
            newmap[alphabet[i]]=widths[i];
        }
        
        int currentWidth=0;
        int totalLine=1;
        for(int i=0;i<s.size();i++)
        {
            if(currentWidth+newmap[s[i]]>100)
            {
                totalLine++;
                currentWidth=0;
            }
            currentWidth+=newmap[s[i]];
        }
        
        res.push_back(totalLine);
        res.push_back(currentWidth);
        return res;
    }
};