class Solution {
public:
    //Sieve of Eratosthenes
    int countPrimes(int n) {
        
        if(n-1 < 2) return 0;
        bool count[n];
        fill_n(count, n, true);
        for(int i = 2; i*i < n; i++ ){
               if(count[i]){
                   for(int j = i*i; j < n; j = j + i){
                       count[j] = false;
                   }
              }
       }
       int result = 0;
       for(int i = 2; i < n; i++){
           if(count[i]) result +=1;
       }
        return result;
        
    }
};