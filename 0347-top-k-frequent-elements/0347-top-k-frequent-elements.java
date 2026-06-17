class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        List<Integer>[] freq = new ArrayList[n+1];
        HashMap<Integer, Integer> m = new HashMap<>();
        for(int i:nums) {
            m.put(i, m.getOrDefault(i,0)+1);
        }

        for(int i: m.keySet()) {
            int count = m.get(i);
            if(freq[count]==null) {
                freq[count] = new ArrayList<>();
            }
            freq[count].add(i);
        }

        int count = 0;
        int[] top = new int[k];
        for(int i=n; i>=0 && count<k; i--) {
            if(freq[i]!=null) {
                List<Integer> val = freq[i];
                for(int j : val) {
                    top[count++] = j;
                }
            }
        }

        return top;
    }
}