class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 ) return s;
        string result;
        int interval = numRows*2 -2;
        
        for(int row = 0; row < numRows; row++){
            int cur = row;
            //insert chars into each row
            while(cur < s.length()){
                //insert char for column 0, 2, 4
                result += s[cur];
                cur += interval;
                //insert char for colummn 1, 3, 5 ....
                if(row > 0 && row < numRows -1 && cur-row*2 < s.length())
                    result += s[cur-row*2];
            }
        }
        return result;
    }
};