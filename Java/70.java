public class Solution {
    //use fibonacci series to solve the problem
    public int climbStairs(int n) {
        if ( n == 0 ) return 0;
        int[][] F = {{1,1}, {1,0}};
        power(F, n);
        return F[0][0];
    }
    
    //Matrix power
    void power(int[][] F, int n){
        if(n == 0 || n == 1) return;
        int[][] M = {{1,1}, {1,0}};
        power(F, n/2);
        multiply(F, F);
        if(n%2 != 0)
            multiply(F, M);
        
    }
    
    void multiply(int[][] F, int [][] M){
        int f00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int f01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int f10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
        int f11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
        
        F[0][0] = f00;
        F[0][1] = f01;
        F[1][0] = f10;
        F[1][1] = f11;
    }
}