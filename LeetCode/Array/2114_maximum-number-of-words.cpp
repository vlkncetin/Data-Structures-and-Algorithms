class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int maxWords=1;
        
        if(sentences.size()==0)
            return 0;
        
        for(int i=0;i<sentences.size();i++)
        {
            int wordCount=1;
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                    wordCount++;
            }
            
            if(wordCount>maxWords)
                maxWords=wordCount;
        }
        
        return maxWords;
    }
};