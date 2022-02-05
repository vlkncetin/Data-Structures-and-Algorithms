class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        vector<vector<string>> result;
        vector<string> tables;
        tables.push_back("Table");
        
        map<int,map<string,int>> tableMap;
        set<string> foods;
        
        for(int i=0;i<orders.size();i++)
        {
            stringstream ss;
            ss<<orders[i][1];
            int tableNumber;
            ss>>tableNumber;
            tableMap[tableNumber][orders[i][2]]++;
            foods.insert(orders[i][2]);
        } 
        
        for (auto it = foods.begin(); it !=foods.end(); ++it)
        {
            tables.push_back(*it); 
        }
        result.push_back(tables);
        
        for(auto m : tableMap)
        {
            vector<string> currenttable;
            stringstream ssTableNum;
            ssTableNum<<m.first;
            currenttable.push_back(ssTableNum.str());
            
            for (auto it = foods.begin(); it !=foods.end(); ++it)
            {
                stringstream ss;
                ss<<m.second[*it];
                currenttable.push_back(ss.str());
            }
            
            result.push_back(currenttable);
        }
        
        return result;
    }
};