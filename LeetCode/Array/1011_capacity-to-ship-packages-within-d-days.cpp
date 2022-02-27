class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxWeight=0;
        int totalWeight=0;
        for(int i=0;i<weights.size();i++)
        {
            maxWeight=max(maxWeight,weights[i]);
            totalWeight+=weights[i];
        }
        
        if(days==1)
            return totalWeight;
        if(days==weights.size())
            return maxWeight;
        
        while (maxWeight < totalWeight) {
            int mid = (maxWeight + totalWeight) / 2, requirement = 1, tillnow = 0;
            for (int w: weights) {
                if (tillnow + w > mid) {
                   requirement += 1;
                   tillnow = 0;
                }
                tillnow += w;
            }
            if (requirement > days) maxWeight = mid + 1;
            else totalWeight = mid;
        }
        
        return maxWeight;
    }
};