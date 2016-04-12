public class Solution {
    public boolean isPalindrome(String s) {
        if(s == null)   return true;
        s = s.toLowerCase();
        int length = s.length();
        int i = 0, j = length - 1;
        char[] chars = s.toCharArray();
        while(i < j){
            
            while(i < length && !Character.isLetterOrDigit(chars[i])){
                i++;
            }
            while(j > -1 && !Character.isLetterOrDigit(chars[j])){
                j--;
            }
            
            if(i < j && chars[i++] != chars[j--])
                return false;
        }
        return true;
    }
    boolean isAlphanumeric(char c){
        String pattern = "[0-9a-zA-Z]";
        return Character.toString(c).matches(pattern);
    }
}