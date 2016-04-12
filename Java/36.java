class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int size = board.size();
        int *row = new int[size]{0};
        int *col = new int[size]{0};
        int *sq = new int[size]{0};
        int tmp;
        //check if it can be solved
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j] - '1';
                    if(val < 0 || val > 8)
                        return false;
                    //check row
                    tmp = 1 << val;
                    if(row[i] & tmp)
                        return false;
                    row[i] |= tmp;
                    //check col
                    if(col[j] & tmp)
                        return false;
                    col[j] |= tmp;
                    //check square
                    int sq_index = (i/3)*3 + (j/3);
                    if(sq[sq_index] & tmp)
                        return false;
                    sq[sq_index] |= tmp;
                }
            }
        }
        delete row;
        delete col;
        delete sq;
        return true;
        
    }
};
