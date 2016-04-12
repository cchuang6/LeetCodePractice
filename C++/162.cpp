class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int i = 0;
        int j = num.size() -1;
        return findPeakHelper(num, i, j);
        
        
    }
    int findPeakHelper(const vector<int> &num, int i, int j){
        if(i == j) return i;
        if(j - i  == 1) return num[i] > num[j] ? i : j;
        int mid = (i+j)/2;
        if(num[mid] > num[mid -1] & num[mid] > num[mid+1])
            return mid;
        else if(num[mid] < num[mid -1])
            return findPeakHelper(num, i, mid-1);
        else
            return findPeakHelper(num, mid+1, j);
    }
};