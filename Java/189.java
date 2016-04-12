public class Solution {
    
    // Reverse the array
    public void reverse(int[] nums, int l, int r) {
        while (l < r) {
            int temp = nums[l];
            nums[l++] = nums[--r];
            nums[r] = temp;
        }
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = (n == 0 ? 0 : k % n);
        reverse(nums, 0    , n - k);
        reverse(nums, n - k, n    );
        reverse(nums, 0    , n    );
    }
}