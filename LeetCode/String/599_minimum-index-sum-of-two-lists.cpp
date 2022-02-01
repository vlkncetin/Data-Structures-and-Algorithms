class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> result;
        int minIndexSum=INT_MAX;
        
        for(int i=0;i<list1.size();i++)
        {
            for(int j=0;j<list2.size();j++)
            {
                if(list1[i]==list2[j])
                {
                    if(minIndexSum==i+j)
                    {
                        result.push_back(list1[i]);
                    }
                    else if(minIndexSum>i+j)
                    {
                        result.clear();
                        result.push_back(list1[i]);
                        minIndexSum=i+j;
                    }
                }
            } 
        }
        
        return result;
    }
};