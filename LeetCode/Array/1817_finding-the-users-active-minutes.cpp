class Solution {
public:
    
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int> answer(k,0);
        
        unordered_map<int,set<int>> myMap;
        
        for(int i=0;i<logs.size();i++)
        {
            myMap[logs[i][0]].insert(logs[i][1]);
        }
        
        for(auto i:myMap)
        {
            answer[i.second.size()-1]++;
        }
        
        return answer;
    }
};