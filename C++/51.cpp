class Solution {
public:
    typedef vector<string> VS;
    typedef vector<vector<string>> VVS;
    typedef vector<int> VI;
    VVS solveNQueens(int n) {
        VVS solutions;
        VI solution(n);
        solveNQueen(0, solutions, solution);
        return solutions;
    }
    void solveNQueen(int i, VVS& solutions, VI& solution){
        //current row is i;
        int n = solution.size();
        if(i >= n){
            solutions.push_back(solToString(solution));
        }
        else{
            for(int j = 0; j < n; j++){
                if(isValid(solution, i, j)){
                    solution[i] = j;
                    solveNQueen(i+1, solutions, solution);
                }
            }
        }
    }
    // try to find if row n, col j is valid
    bool isValid(VI& solution, int row, int col){
        //search previous row
        for(int i = 0; i < row; i++){
            // if previous row value is the same or distance between row is equal to distance between col
            if(solution[i] == col || abs(row-i) == abs(col - solution[i]))
                return false;
        }
        return true;
    }
    VS solToString(VI& solution){
        int n = solution.size();
        VS solString;
        for(int i = 0; i < n; i++){
            solString.push_back(string(n, '.'));
            solString[i].replace(solution[i], 1, "Q");
        }
        return solString;
    }
};