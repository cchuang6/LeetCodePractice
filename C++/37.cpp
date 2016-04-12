class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        // try to solve here
        doSolve(board);
    }
    bool doSolve(vector<vector<char>> &board){
        // try to solve here
        int row, col;
        if(!findUnAssinged(board, row, col))
            return true;
        for(int num = 1; num <= 9; num++)
        {
            //try to assign a value
            board[row][col] = char(num + '0');
            if(!isValid(board))
                continue;
            if(doSolve(board))
                return true;
                
        }
        board[row][col] = '.';
        return false;
        
    }
    bool findUnAssinged(vector<vector<char>> &board, int& row, int & col){
        int size = board.size();
        for(row = 0; row < size; row++)
            for(col = 0; col < size; col++)
                if(board[row][col]=='.')
                    return true;
        return false;
    }
    
    bool isValid(vector<vector<char>> &board){
        int row_size = board.size();
        int col_size = board[0].size();
        int row[row_size] = {0};
        int col[col_size] = {0};
        int sq[row_size] = {0};
        int tmp;
        //check if it can be solved
        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < col_size; j++){
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
        return true;
        
    }
    
    //
};
