class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.size()==0)
            return res;
        map<string,vector<string>> buttonMap;
        vector<string> b2;
        b2.push_back("a");
        b2.push_back("b");
        b2.push_back("c");
        buttonMap["2"]=b2;
        
        vector<string> b3;
        b3.push_back("d");
        b3.push_back("e");
        b3.push_back("f");
        buttonMap["3"]=b3;
        
        vector<string> b4;
        b4.push_back("g");
        b4.push_back("h");
        b4.push_back("i");
        buttonMap["4"]=b4;
        
        vector<string> b5;
        b5.push_back("j");
        b5.push_back("k");
        b5.push_back("l");
        buttonMap["5"]=b5;
        
        vector<string> b6;
        b6.push_back("m");
        b6.push_back("n");
        b6.push_back("o");
        buttonMap["6"]=b6;
        
        vector<string> b7;
        b7.push_back("p");
        b7.push_back("q");
        b7.push_back("r");
        b7.push_back("s");
        buttonMap["7"]=b7;
        
        vector<string> b8;
        b8.push_back("t");
        b8.push_back("u");
        b8.push_back("v");
        buttonMap["8"]=b8;
        
        vector<string> b9;
        b9.push_back("w");
        b9.push_back("x");
        b9.push_back("y");
        b9.push_back("z");
        buttonMap["9"]=b9;
        
        std::string s;
        s.push_back(digits[0]);
        res=buttonMap[s];
        
        for(int i=1;i<digits.size();i++)
        {
            vector<string> resTemp;
            std::string sTemp;
            sTemp.push_back(digits[i]);
            
            for(int j=0;j<buttonMap[sTemp].size();j++)
            {
                for(int k=0;k<res.size();k++)
                {
                    string temp="";
                    temp.append(res[k]).append(buttonMap[sTemp][j]);
                    resTemp.push_back(temp);
                }
            }
            
            res=resTemp;
            
        }
        
        return res;
    }
};