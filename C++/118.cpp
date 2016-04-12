class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        res.push_back(vector<int>(1,1));
        for(int i = 1; i < numRows; i++){
            vector<int> new_row (1,1);
            for(int j = 1; j < i; j++){
                new_row.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            new_row.push_back(1);
            res.push_back(new_row);
            //new_row.clear();
        }
        return res;
        
    }
    
    //Binomail coefficent
    int binomialCoef(int m, int n){
        int res = 1;
        if(n > m-n)
            n = m-n;
        for(int i = 0; i < n; i++){
            res *= (m-i);
            res /= (i+1);
        }
        return res;
    }
};

