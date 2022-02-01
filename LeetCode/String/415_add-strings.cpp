class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res="";
        bool isSumBiggerThanTen=false;
        
        bool isNum1Finished=false;
        bool isNum2Finished=false;
        for(int i=num1.size()-1,j=num2.size()-1;i>=0 || j>=0;i--,j--)
        {
            int digit1=0,digit2=0,digitSum;
            stringstream ssDigit1,ssDigit2,ssDigitSum;
            
            if(!isNum1Finished)
            {
                ssDigit1<<num1[i];
                ssDigit1>>digit1;
            }
            
            if(!isNum2Finished)
            {
                ssDigit2<<num2[j];
                ssDigit2>>digit2;
            }
            
            digitSum=digit1+digit2;
            
            if(isSumBiggerThanTen)
                digitSum++;
            
            if(digitSum>=10)
                isSumBiggerThanTen=true;
            else
                isSumBiggerThanTen=false;
            
            ssDigitSum<<digitSum%10;
            
            res=ssDigitSum.str().append(res);
            
            if(i==0)
                isNum1Finished=true;
            if(j==0)
                isNum2Finished=true;
        }
        
        if(isSumBiggerThanTen)
        {
            string temp="1";
            res=temp.append(res);
        }
        
        return res;
    }
};