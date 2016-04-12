class Solution {
public:
//Using Heaps algorithm
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        int counter = num.size();
        doPermute(result, counter, num);
        return result;
        
    }
    void doPermute(vector<vector<int>>& result, int counter, vector<int>& num){
        if(counter == 1){
            result.push_back(num);
        }
        else{
            for(int i = 1; i <= counter; i++){
                doPermute(result, counter-1, num);
                if( (counter%2) == 1){
                    //swap the first and last
                    swap(num, 0, counter-1);
                }
                else{
                    //swap current and last
                    swap(num, i-1, counter-1);
                }
            }
        }
    }
    
    void swap(vector<int>& num, int i, int j){
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
};