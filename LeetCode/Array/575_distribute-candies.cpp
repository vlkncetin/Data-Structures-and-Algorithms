class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_map<int,int> candyMap;
        for(int i=0;i<candyType.size();i++)
        {
            candyMap[candyType[i]]++;
        }
        
        int halfCandies=candyType.size()/2;
        int totalType=0;
        
        for(auto m:candyMap)
        {
            totalType++;
            if(totalType>halfCandies)
                return halfCandies;
        }
        
        return totalType;
    }
};