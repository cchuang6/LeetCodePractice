class Solution {
public:
    int romanToInt(string s) {
        
        if ( s.empty()) return 0;
        
        //：Ⅰ（1）Ⅴ（5）Ⅹ（10）L（50）C（100）D（500）M（1000)
        
        // using array
        int map[26];

        memset(map, 0, 26);

        map['I'-'A']=1;
        map['V'-'A']=5;
        map['X'-'A']=10;
        map['L'-'A']=50;
        map['C'-'A']=100;
        map['D'-'A']=500;
        map['M'-'A']=1000;
        
        
        int sLength = s.length();
        int pivot, result;
        result = pivot = map[s[sLength - 1]- 'A'];
        for(int i = sLength - 2; i > -1; i--  ){
            int curr = map[s[i]-'A'];
            if(curr < pivot){
                result -= curr;
            }
            else{
                result += curr;
            }
            pivot = curr;
        }
        return result;
    }
};