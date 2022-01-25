class Solution {
public:
    double average(vector<int>& salary) {
        
        int minSalary=INT_MAX;
        int maxSalary=INT_MIN;
        int sum=0;
        
        for(int i=0;i<salary.size();i++)
        {
            minSalary=min(minSalary, salary[i]);
            maxSalary=max(maxSalary, salary[i]);
            sum+=salary[i];
        }
        
        double res=(double)(sum-maxSalary-minSalary)/(salary.size()-2);
        
        return res;
    }
};