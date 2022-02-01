class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.size()>magazine.size())
            return false;
        
        for(int i=ransomNote.size()-1;i>=0;i--)
        {
            char c=ransomNote[i];
            
            size_t found=magazine.find(c);
            
            if(found==string::npos)
                return false;
            else
                magazine.erase(magazine.begin()+found);
            
            ransomNote.erase(ransomNote.begin()+i);
        }
        
        return true;
    }
};