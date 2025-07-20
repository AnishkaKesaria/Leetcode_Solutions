class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[') {
                System.out.println("pushing");
                st.push(s.charAt(i));
            }
            else {
                if(st.isEmpty())
                    return false;
                else {
                    char top = st.pop();
                    System.out.println(top);
                    if(top=='(') {
                        if(s.charAt(i)!=')')
                            return false;
                    } else if (top=='[') {
                        if(s.charAt(i)!=']')
                            return false;
                    } else {
                        if(s.charAt(i)!='}')
                            return false;
                    }
                }
            }
        } 
        return st.isEmpty();
    }
}