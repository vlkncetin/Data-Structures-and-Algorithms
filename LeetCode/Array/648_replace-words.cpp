class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
     
        //First split sentence with space and get a vector
        vector<string> words;
        while(1)
        {
            size_t found=sentence.find(" ");
            if(found==string::npos)
            {
                words.push_back(sentence);
                break;
            }
            else
            {
                string word=sentence.substr(0, found);
                words.push_back(word);
                sentence.erase(0, found+1);
            }
        } 
        
        stringstream ssResult;
        for(int i=0;i<words.size();i++)
        {
            int shortestDictionary=INT_MAX;
            for(int j=0;j<dictionary.size();j++)
            {
                if(words[i][0]!=dictionary[j][0])
                {
                    continue;
                }
                size_t found=words[i].find(dictionary[j]);
                if(found==0)
                {
                    if(dictionary[j].size()<shortestDictionary)
                    {
                        words[i]=dictionary[j];
                        shortestDictionary=dictionary[j].size();
                    }
                }
            }
            ssResult<<words[i];
            if(i!=words.size()-1)
                ssResult<<" ";
        }
        
        return ssResult.str();
    }
};