public class Solution {
    public int removeDuplicates(int[] nums) {
        // i is the the results of array length
        // every time, check the last element of the current array with length i
        int i = 0;
        for(int n : nums){
            if(i == 0 || n > nums[i-1]){
                nums[i++] = n;
            }
        }
        return i;
        
    }
}