public class Solution {
    public int removeElement(int[] nums, int val) {
        int newIndex = 0;
        int curr = 0;
        
        for(curr = 0; curr < nums.length; curr++){
            if(nums[curr] != val){
                nums[newIndex] = nums[curr];
                newIndex++;
            }
        }
        return newIndex;
        
    }
}