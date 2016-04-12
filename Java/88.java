public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(m == 0 & n == 0) return;
        int index1 = m -1;
        int index2 = n -1;
        int cur = m + n -1;
        while(index1 >=0 && index2 >=0){
            if(nums1[index1] > nums2[index2]) nums1[cur--] = nums1[index1--];
            else nums1[cur--] = nums2[index2--];
        }
        if(cur >=0){
            while(index2>=0)
                nums1[cur--] = nums2[index2--];
        }
    }
}