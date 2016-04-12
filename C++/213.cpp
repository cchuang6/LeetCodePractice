class Solution {
public:
    int rob(vector<int>& nums) {
        if( nums.size() == 0) return 0;
        if( nums.size() == 1) return nums[0];
        
        return max(robHelper(nums, 0, nums.size()-1), robHelper(nums, 1, 0));
    }
    
    int robHelper(vector<int>& nums, int start, int end){
        int curr = 0;
        int prev_noRob = 0;
        for(int i = start; i != end; i = (i+1)% nums.size()){
            int temp = max(curr, prev_noRob + nums[i] );
            prev_noRob = curr;
            curr = temp;
        }
        return curr;
    }
};