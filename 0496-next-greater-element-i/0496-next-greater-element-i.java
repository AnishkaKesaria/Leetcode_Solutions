class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> m = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        for(int n: nums2) {
            while(!st.isEmpty() && n>st.peek()){
                m.put(st.pop(), n);
            }
            st.push(n);
        }

        int[] ans = new int[nums1.length];
        for(int i=0; i<nums1.length; i++) {
            if(m.containsKey(nums1[i]))
                ans[i] = m.get(nums1[i]);
            else
                ans[i] = -1;
        }

        return ans;
    }
}