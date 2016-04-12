public class Solution {
    public String countAndSay(int n) {
        if(n == 0) return "";
        String result = "1";
        for(int i = 1; i<n; i++ ){
            String pre = "";
            char currChar = result.charAt(0);
            int count = 1;
            for(int j = 1; j < result.length(); j++){
                if(currChar == result.charAt(j)){
                    count++;
                }
                else{
                    pre += Integer.toString(count) + currChar;
                    currChar = result.charAt(j);
                    count = 1;
                }
            }
            result = pre + Integer.toString(count) + currChar;
        }
        return result;
    }
}
