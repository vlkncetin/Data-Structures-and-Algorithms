class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        int index=0;
        
        while(num>0)
        {
           if(num>=nums[index])
           {
               result += romans[index];
               num  = num - nums[index];
               index = -1;
           }
           index++;
        }
        
        return result;
    }
};