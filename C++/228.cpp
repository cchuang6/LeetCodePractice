class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i = 0; i < nums.size();){
            //next one
            int j = i + 1;
            //check consecutive
            while(j < nums.size() && (j - i) == nums[j]-nums[i] ) j++;
            //range
            if(j > i + 1){
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            }
            //single number
            else{
                result.push_back(to_string(nums[i]));
            }
            //update
            i = j;
        }
        return result;
    }
};