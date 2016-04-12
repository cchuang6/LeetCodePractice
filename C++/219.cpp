class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        if(!k) return false;
        if(k > nums.size() -1) k = nums.size() -1;
        //check the first k difference
        for(int i = 0; i <=k; i++){
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
            }
            else
                return true;
        }
        //check the index greater than k
        for(int i= k+1; i < nums.size(); i++){
            //delete the set with nums[i-k-1] value
            set.erase(nums[i-k-1]);
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
            }
            else
                return true;
        }
        return false;
    }
};