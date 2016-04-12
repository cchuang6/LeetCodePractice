class Solution {
public:
    int myAtoi(string str) {
        //discard whitespace
        // or use iterator
        //(for string::iterator it = str.begin(); it !+ str.end(); it++)
        // deal with '+' or '-'
        int i = 0;
        while(str[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        // sign handling
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            // handle + explicitely
            i++;
        }
        int num = 0;
        bool overflow = false;
        bool startCount = false;
        int digitCount = 0;
        int highNumber = 0;
        // if its too large a number, then stop once it reaches INT_MAX
        while(isdigit(str[i])) {
            // while its a digit, skip rest
            
            int d = str[i]-'0';
            
            if(!startCount && d > 0){
                highNumber = d;
                startCount = true;
            }
            
            if(startCount){
                //check overflow before adding it
                digitCount += 1;
                if(digitCount > 10 || (digitCount == 10 && highNumber > 2)){
                    overflow = true;
                    break;
                }
                
                num = (num<< 3) + (num << 1) + d;
                
                //check overflow after adding it
                if(num < 0){
                    overflow = true;
                    break;
                }
            }
            i++;
        }
    
        // out of range handling
        if(overflow){
            if(sign == 1) return INT_MAX;
                else return INT_MIN;
        }
        
        if(sign == -1) return (~num)+1;
        else return num;
    }
    bool isdigit(char c){
        return (0 <= c - '0') && (c - '0' <= 9) ? true : false;
    }
};