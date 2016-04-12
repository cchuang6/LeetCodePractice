public class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null || matrix.length == 0) return;
        
        int n = matrix.length;
        //transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //swap head and tail for each line
        for(int i = 0; i < n; i++){
            reverse(matrix[i]);
        }
    }
    
    void reverse(int[] row){
        int n = row.length;
        for(int i = 0; i < n/2; i++){
            int temp = row[i];
            row[i] = row[n - 1 -i];
            row[n - 1 - i] = temp;
        }
    }
    
}