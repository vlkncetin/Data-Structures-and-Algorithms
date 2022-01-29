class Solution {
public:
    int firstUniqChar(string s) {
        int index =-1;
        for(int i=0;i<s.size();i++)
        {
            char ccc=s[i];
            bool isUnique=true;
            for(int j=0;j<s.size();j++)
            {if(i==j) continue;
                if(ccc==s[j])
                {
                    isUnique=false;
                    break;
                }
            }
            if(isUnique) return i;
            
        }
        return index;
    }
};