class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string temp=s;
        
        for(int i=0;i<indices.size();i++)
        {
            s[indices[i]]=temp[i];
        }
        
        return s;
    }
};