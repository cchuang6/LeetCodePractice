class Solution {
public:
    int totalNQueens(int n) {
        int done = (1 << n) -1;
        int ld, col, rd;
        ld = col = rd = 0;
        int count = 0;
        solve(ld, col, rd, done, count);
        return count;
    }
    
    //http://gregtrowbridge.com/a-bitwise-solution-to-the-n-queens-problem-in-javascript/
    void solve(int ld, int col, int rd, int done, int &count){
        if(col == done){
            count++;
            return;
        }
        int pos = ~(ld | rd | col);
        while( pos& done){
            int bit = pos & (~pos +1);
            pos -= bit;
            solve((ld | bit)>>1, col | bit, (rd | bit)<<1, done, count);
        }
    }
};