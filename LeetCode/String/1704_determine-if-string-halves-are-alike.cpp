class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='A' || c=='a' ||c=='E' ||c=='e' ||c=='I' ||c=='i' ||c=='O' ||c=='o' ||c=='U' ||c=='u' )
            return true;
        
        return false;
    }
    bool halvesAreAlike(string s) {
        
        int vowelFirstHalf=0;
        int vowelSecondHalf=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(i<s.size()/2 && isVowel(s[i]))
                vowelFirstHalf++;
            if(i>=s.size()/2 && isVowel(s[i]))
                vowelSecondHalf++;
        }
        
        if(vowelFirstHalf==vowelSecondHalf)
            return true;
        
        return false;
    }
};