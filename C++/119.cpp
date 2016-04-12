class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        if(rowIndex <= 1) return res;
        for(int i = 1; i < rowIndex; i++){
            int prev = res[0];
            for(int j = 1; j <= i; j++){
                int temp = res[j];
                res[j] = res[j]+prev;
                prev = temp;
            }
        }
        return res;
        
    }
};