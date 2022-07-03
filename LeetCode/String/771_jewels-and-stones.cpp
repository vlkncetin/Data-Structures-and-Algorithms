class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_map<char,int> stoneMap;
        
        for(int i=0;i<stones.size();i++)
        {
            stoneMap[stones[i]]++;
        }
        
        int sum=0;
        
        for(int i=0;i<jewels.size();i++)
        {
            sum+=stoneMap[jewels[i]];
        }
        
        return sum;
    }
};