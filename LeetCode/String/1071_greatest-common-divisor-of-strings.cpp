class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        string res="";
        string small=str2,large=str1;
        if(str1.size()<str2.size())
        {
            small=str1;
            large=str2;
        }
        
        vector<string> dividerOfSmall;
        for(int i=0;i<small.size();i++)
        {
            string temp=small.substr(0,i+1);
            while(temp.size()<small.size())
            {
                temp+=small.substr(0,i+1);
            }
            if(temp==small)
                dividerOfSmall.push_back(small.substr(0,i+1));
        }
        
        for(int i=dividerOfSmall.size()-1;i>=0;i--)
        {
            string temp=dividerOfSmall[i];
			
            while(temp.size()<large.size())
            {
                temp+=dividerOfSmall[i];
            }
			
            if(temp==large)
                return dividerOfSmall[i];
        }
        
        return res;
    }
};