class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int res=0;
        
        // a=97, b=122
        vector<string> morse_letters{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string,vector<string>> transformations;
        
        for(int i=0;i<words.size();i++)
        {
            string morse="";
            for(int j=0;j<words[i].size();j++)
            {
                morse.append(morse_letters[(int)words[i][j]-97]);
            }
            
            transformations[morse].push_back(words[i]);
        }
        
        res=transformations.size();
        
        return res;
    }
};