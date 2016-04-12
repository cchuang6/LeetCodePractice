class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0;
        int no_Robprev = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = max(curr, no_Robprev+nums[i]);
            no_Robprev = curr;
            curr = temp;
        }
        return curr;
    }
};