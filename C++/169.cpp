class Solution {
public:
    int majorityElement(vector<int> &num) {
        //http://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
        int majority;
        int count = 0;
        for(int i = 0; i < num.size(); i++){
            if(count == 0)
                majority = num[i];
            if(majority == num[i])
                count++;
            else
                count--;
        }
        return majority;
    }
};