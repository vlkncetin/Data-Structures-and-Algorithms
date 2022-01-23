class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        bool isDescending=false;
        bool isAscending=true;
        
        if(arr.size()<3)
            return false;
        
        if(arr.size()==3)
        {
            if(arr[1]>arr[0] && arr[1]>arr[2])
                return true;
            else 
                return false;
        }
        
        if(arr.size()>3)
        {
            if(arr[0]>arr[1])
                return false;
        }
        
        vector<int> newVec=arr;
        sort(newVec.begin(),newVec.end());
        int maxVal=newVec[newVec.size()-1];
        
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]==arr[i+1])
                return false;
            else if(arr[i]==maxVal)
            {
                isAscending=false;
                isDescending=true;
            }
            
            if(isAscending)
            {
                if(arr[i]>arr[i+1])
                {
                    return false;
                }
            }
            else
            {
                if(arr[i]<arr[i+1])
                {
                   return false;
                }
            }
        }
        
        if(!isDescending)
            return false;
                
        return true;
    }
};