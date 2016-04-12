class Solution {

private: 
    int area(int left, int right, int bottom, int top){
        return (right > left && top > bottom) ? (right -left) * (top - bottom) : 0;
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left1 = A;
        int bottom1 = B;
        int right1 = C;
        int top1 = D;
        int left2 = E;
        int bottom2 = F;
        int right2 = G;
        int top2 = H;
        
        int innerL = max(left1, left2);
        int innerR = min(right1, right2);
        int innerB = max(bottom1, bottom2);
        int innerT = min(top1, top2);
        
        return area(left1, right1, bottom1, top1) + area(left2, right2, bottom2, top2) - area(innerL, innerR, innerB, innerT); 
        
    }
    
};