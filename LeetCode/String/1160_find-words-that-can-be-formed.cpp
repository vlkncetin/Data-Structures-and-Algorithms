class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int totalLenght=0;
        
        for(int i=0; i<words.size();i++)
        {
            string temp=chars;
            bool canBeFormed=true;
            for(int j=0;j<words[i].size();j++)
            {
                stringstream ss;
                ss<<words[i][j];
                size_t found=temp.find(ss.str());
                if(found==string::npos)
                {
                    canBeFormed=false;
                    break;
                }
                else
                {
                    temp.erase(temp.begin()+found);
                }
            }
            if(canBeFormed)
                totalLenght+=words[i].size();
        }
        
        return totalLenght;
    }
};