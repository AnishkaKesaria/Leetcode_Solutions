class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a,b)->Integer.compare(a[0],b[0]));
        int s = intervals[0][0];
        int e = intervals[0][1];

        for(int i=1; i<intervals.length; i++) {
            int curr = intervals[i][0];
            if(curr<=e)
            {
                s = Math.min(s, curr);
                e = Math.max(e, intervals[i][1]);
            } else {
                ans.add(new int[]{s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.add(new int[]{s,e});
        return ans.toArray(new int[ans.size()][]);
    }
}