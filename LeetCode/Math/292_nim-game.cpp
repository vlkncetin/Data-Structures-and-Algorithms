class Solution {
public:
    bool canWinNim(int n) {
        // n=1 win
        // n=2 win
        // n=3 win
        // n=4 lose
        // n=5 win
        // n=6 win
        return n%4 != 0;
    }
};