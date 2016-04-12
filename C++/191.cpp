class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // n 1-  = 0110 - 1 = 0101
        // n & (n-1) = 0110 & 0001 = 0100
        while(n){
            n &= (n-1);
            count++;
        }
        return count;   
    }
};