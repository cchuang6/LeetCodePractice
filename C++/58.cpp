class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum = 0, i = s.length() -1;
        for(;i> -1; i--){
            if(sum>0 && s[i]==' ')
                return sum;
            if(s[i] == ' ')
                continue;
            sum++;
        }
        return sum;
    }
};