class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length())
            return false;

        Map<Character,Integer> s1 = new HashMap();
        Map<Character,Integer> s2 = new HashMap();

        for(int i=0; i<s.length(); i++) {
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);

            s1.put(ch1, s1.getOrDefault(ch1,0)+1);
            s2.put(ch2, s2.getOrDefault(ch2,0)+1);
        }

        return s1.equals(s2);
    }
}