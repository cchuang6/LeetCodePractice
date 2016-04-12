class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(string::iterator it = s.begin(); it != s.end(); it++){
            result = result*26 + (*it - 'A') + 1;
        }
        return result;
        
    }
};