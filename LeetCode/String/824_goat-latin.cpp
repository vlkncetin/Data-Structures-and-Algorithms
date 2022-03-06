class Solution {
public:
    string toGoatLatin(string sentence) {
        
        stringstream ss;
        string word="";
        int wordIndex=0;
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ' || (i==sentence.size()-1))
            {
                wordIndex++;
                if(i==sentence.size()-1)
                    word.push_back(sentence[i]);
                if(word[0]=='A'||word[0]=='a'||word[0]=='E'||word[0]=='e'||word[0]=='I'||word[0]=='i'||word[0]=='O'||word[0]=='o'||word[0]=='U'||word[0]=='u')
                {
                    word=word.append("ma");
                }
                else
                {
                    word.push_back(word[0]);
                    word.erase(word.begin());
                    word=word.append("ma");
                }
                for(int j=0;j<wordIndex;j++)
                    word.push_back('a');
                
                ss<<word;
                if(i!=sentence.size()-1)
                    ss<<" ";
                word="";
            }
            else
            {
                word.push_back(sentence[i]);
            }
        }
        
        return ss.str();
    }
};