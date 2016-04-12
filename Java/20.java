public class Solution {
    public boolean isValid(String s) {
        char[] chars = s.toCharArray();
        Stack stack = new Stack();
        for(char ch : chars){
            if(stack.isEmpty()){
                stack.push(ch);
            }
            else{
                if(ch - (char)stack.peek() == 1 || ch - (char)stack.peek() == 2)
                    stack.pop();
                else
                    stack.push(ch);
            }
        }
        return stack.isEmpty();
        
    }
}