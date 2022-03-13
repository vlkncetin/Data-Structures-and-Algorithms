class Solution {
public:
    bool divisorGame(int n) {
        if(n==1)
            return false; //Alice lost the game
        vector<int> dp(n+1,false);
        
        for(int i=2;i<=n;i++)
        { 
            for(int j=1;j<=i/2;j++) //j<i also works but slower
            { 
                if(i%j==0 && !dp[i-j])
                    dp[i]=true;
            }
        }
                
        return dp[n];
    }
};