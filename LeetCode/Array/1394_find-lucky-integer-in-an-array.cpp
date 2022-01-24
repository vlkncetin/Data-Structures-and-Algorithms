class Solution {
    
struct MyStruct{
    int num=0;
    int freq=0;
};
    
public:
    int findLucky(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        vector<MyStruct> newVec;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(newVec.size()==0)
            {
                MyStruct str;
                str.num=arr[i];
                str.freq=1;
                newVec.push_back(str);
            }
            else
            {
                if(arr[i]==newVec[newVec.size()-1].num)
                {
                    newVec[newVec.size()-1].freq=newVec[newVec.size()-1].freq+1;
                }
                else
                {
                    MyStruct str;
                    str.num=arr[i];
                    str.freq=1;
                    newVec.push_back(str);
                }
            }
        }
        
        for(int i=newVec.size()-1;i>=0;i--)
        {
            if(newVec[i].num==newVec[i].freq)
                return newVec[i].num;
        }
        
        return -1;
    }
};