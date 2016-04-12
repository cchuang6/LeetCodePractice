public class Solution {
    public boolean exist(char[][] board, String word) {
        char[] wchars = word.toCharArray();
        for(int row = 0; row < board.length; row++){
            for(int col = 0; col < board[row].length; col++){
                if(searchHelper(board, row, col, wchars, 0)) return true;
            }
        }
        return false;
    }
    
    //search helper
    private boolean searchHelper(char[][] board, int row, int col, char[] word, int index){
        //return true when finishing word search
        if(index == word.length) return true;
        //return false when the board coordinate is out of the check box boundary
        if(row < 0 || col < 0 || row == board.length || col == board[row].length) return false;
        //return false when word does not match
        if(board[row][col] != word[index]) return false;
        //markd the word is searched
        board[row][col] ^= 256;
        //continue search, left, right, top, down
        boolean exist = searchHelper(board, row - 1, col, word, index + 1) ||
                        searchHelper(board, row + 1, col, word, index + 1) ||
                        searchHelper(board, row, col - 1, word, index + 1) ||
                        searchHelper(board, row, col + 1, word, index + 1);
        //restore the marked word
        board[row][col] ^= 256;
        return exist;
    }
}