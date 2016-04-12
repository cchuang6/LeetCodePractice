class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = (~x) + 1;
        }
        int result = 0;
        bool overflow = false;
        int digit_num = 0;
        int msb = 0;
        
        while(x != 0){
            if(msb == 0 ){
                msb = x%10;
            }
            if(msb != 0){
                digit_num++;
                if(digit_num > 10 || ((digit_num == 10) && msb > 2)){
                    overflow = true;
                    break;
                }
                result = (result<<3) + (result << 1) + (x % 10);
                //deal with overflow
                if(result < 0){
                    overflow = true;
                    break;
                }
            }
            x /= 10;
        }
        
        if(overflow)
            return 0;
        if(sign == -1){
            return result = (~result) + 1;
        }
        else
            return result;
        
    }
};