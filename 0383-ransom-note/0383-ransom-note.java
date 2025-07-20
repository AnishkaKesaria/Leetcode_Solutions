class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> m = new HashMap<>();
        for(char c: magazine.toCharArray()) {
            m.put(c, m.getOrDefault(c,0)+1);
        }

        for(char c: ransomNote.toCharArray()) {
            if(!m.containsKey(c) ||  m.get(c)==0)
                return false;
            m.put(c, m.get(c)-1);
        }

        return true;
    }
}