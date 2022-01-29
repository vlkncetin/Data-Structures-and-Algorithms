class Solution {
public:
    void reverseString(vector<char>& s) {
        
        vector<char> s2(s);
        for(int i=0;i<s.size();i++)
        {
            s[i]=s2[s2.size()-i-1];
        }
    }
};