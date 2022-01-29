class Solution {
public:
   
    string convertMonth(string month)
    {
        if(month=="Jan")
            return "01";
        else if(month=="Feb")
            return "02";
        else if(month=="Mar")
            return "03";
        else if(month=="Apr")
            return "04";
        else if(month=="May")
            return "05";
        else if(month=="Jun")
            return "06";
        else if(month=="Jul")
            return "07";
        else if(month=="Aug")
            return "08";
        else if(month=="Sep")
            return "09";
        else if(month=="Oct")
            return "10";
        else if(month=="Nov")
            return "11";
        else if(month=="Dec")
            return "12";
        
        return "01";
    }
    
    string reformatDate(string date) {
        
        //parse day
        size_t found=date.find(" ");
        string day=date.substr(0,found-2); //do not get "rd, th, st" etc.
        if(day.size()==1)
            day.insert(day.begin(),'0');
        date.erase(0,found+1);
        
        //parse month and year
        string month=date.substr(0,3);
        month=convertMonth(month);
        string year=date.substr(4,4);
        
        stringstream ss;
        ss<<year<<"-"<<month<<"-"<<day;
            
        return ss.str();
    }
};