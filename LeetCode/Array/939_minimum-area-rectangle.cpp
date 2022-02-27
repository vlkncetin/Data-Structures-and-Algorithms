class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        map<int,vector<int>> xAxes;

        for(int i=0;i<points.size();i++)
            xAxes[points[i][0]].push_back(points[i][1]);

        map<pair<int,int>,int > lastx;

        int ans = INT_MAX;

        for (auto x:xAxes)
        {
            vector<int> column = x.second;
            sort(column.begin(), column.end());
            for (int j = 0; j < column.size(); j++)
            {
                for (int i = 0; i < j; i++)
                {
                    int y1 = column[i];

                    if (lastx.find({y1, column[j]}) != lastx.end())
                    {
                        ans = min(ans, (x.first - lastx[{y1, column[j]}]) * (column[j] - column[i]));
                    }
                    lastx[{y1, column[j]}] = x.first;
                }
            }
        }

        if (ans < INT_MAX)
            return ans;
        else
            return 0;
    }
};