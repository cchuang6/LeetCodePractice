class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        vector<vector<int>> result;
        if (num.size() <= 1){
            result.push_back(num);
            return result;
        }
        sort(num.begin(), num.end());
        result.push_back(num);
        generate(result, num);
        return result;
    }
    void generate(vector<vector<int>>& result, vector<int>& num){
        int size = num.size();
        //find the largest index i where num[i] < num[i+1]
        int i;
        for(i = size - 2; i >=0; i--){
            if(num[i] < num[i+1]){
                break;
            }
                
        }
        if(i < 0)
            return;
        //find the largest index j after i where num[j] is the smallest one in sub array
        int j;
        for(j = size -1; j-1> i; j--){
            if(num[i]<num[j]){
                break;
            }
        }
        
        //swap
        swap(num, i, j);
        //reverse
        reverse(num, i+1, size-1);
        result.push_back(num);
        
        generate(result, num);
    }
    void swap(vector<int>& num, int i, int j){
        if(i == j) return;
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    void reverse(vector<int>& num, int start, int end){
        while(start < end){
            swap(num, start, end);
            start++;
            end--;
        }
    }
};