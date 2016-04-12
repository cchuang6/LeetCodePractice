public class Solution {
    public int[] plusOne(int[] digits) {
        return plusHelper(digits, digits.length -1);
    }
    
    int[] plusHelper(int[] digits, int index){
        if(digits[index] < 9){
            digits[index] += 1;
            return digits;
        }
        else{
            if(index != 0 ){
                digits[index--] = 0;
                return plusHelper(digits, index);
            }
            else{
                int[] newDigits = new int[digits.length + 1];
                newDigits[0] = 1;
                return newDigits;
            }
        }
    }
}