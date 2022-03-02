class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int area=abs((ax1-ax2)*(ay1-ay2))+abs((bx1-bx2)*(by1-by2));
        
        if (ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1 || ay1 >= by2)
            return area; 
        
        return area - (min(bx2, ax2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
    }
};