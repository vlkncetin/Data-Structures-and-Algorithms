class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> result;
        
        for(int i=0;i<boxes.size();i++)
        {
            int counterSum=0;
            
            for(int j=0;j<boxes.size();j++)
            {
                if(boxes[j]=='1')
                    counterSum+=abs(j-i);
            }
            
            result.push_back(counterSum);
        }
        
        return result;
    }
};