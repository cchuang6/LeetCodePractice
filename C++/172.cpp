class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        if(n < 1) return count;
        while(n > 0){
            n = n/5;
            count += n;
        }
        return count;
    }
};