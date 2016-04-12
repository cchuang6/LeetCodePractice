class Solution {
public:
    int mySqrt(int x) {
        //Xn+1 = Xn - f(x)/f'(x)
        //f(x) = x^2 - s 
        
        double x_n = (double)x/2.0;
        double x_n1;
        double eps = 0.001;
        while(abs(x_n*x_n - x) >= eps){
            x_n1 = x_n - (x_n*x_n - x)/(2*x_n);
            x_n = x_n1;
        }
        return (int)x_n;
    }
};