class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int max=0;
         
        vector<int> stateStr;

        for(int i=0; i<words.size(); i++)
        {
          stateStr.push_back(getStateFromStr(words[i]));
        }
        
        for(int i=0; i<words.size(); i++)
        {
            for(int j = i+1; j<words.size() ; j++)
            {
                if( (stateStr[i] & stateStr[j]) == 0 && words[i].size() * words[j].size() > max )  
                {
                    max = words[i].size() * words[j].size();
                }
            }
        }
        
        return max;
    }
    
    int getStateFromStr(string s)
    {
         int state = 0;
        
         for(char ch: s)
         {
             state |=  1 << (ch - 'a');
         }
        
         return state;
    }
};