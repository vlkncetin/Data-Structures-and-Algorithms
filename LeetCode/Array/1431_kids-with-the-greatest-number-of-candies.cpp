class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandy=-1;
        
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>maxCandy)
                maxCandy=candies[i];
        }
        
        vector<bool> res;
        
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maxCandy)
                res.push_back(true);
            else
                res.push_back(false);
        }
        
        return res;
    }
};