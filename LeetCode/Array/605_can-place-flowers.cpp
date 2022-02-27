class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int numOfNewPlants=0;
        
        if(n==0)
            return true;
        
        if(flowerbed.size()==1)
        {
            if(flowerbed[0]==1)
                return false;
            else if(flowerbed[0]==0 && n==1)
                return true;
        }
        
        if(flowerbed[0]==0 && flowerbed[1]==0)
        {
            flowerbed[0]=1;
            numOfNewPlants++;
            if(numOfNewPlants==n)
                return true;
        }
        
        for(int i=1;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                numOfNewPlants++;
                if(numOfNewPlants==n)
                    return true;
            }
        }
        
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0)
        {
            numOfNewPlants++;
            if(numOfNewPlants==n)
                return true;
        }
        
        if(numOfNewPlants>=n)
            return true;
        return false;
    }
};