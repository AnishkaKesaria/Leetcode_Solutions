class KthLargest {
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();

    public KthLargest(int k, int[] nums) {
        // PriorityQueue<Integer> minHeap = new PriorityQueue<>();


        for(int i=0; i<k; i++) {
            minHeap.add(Integer.MIN_VALUE);
        }

        for(int i=0; i<nums.length; i++) {
            int top = minHeap.peek();
            if(nums[i]>top) {
                minHeap.poll();
                minHeap.add(nums[i]);
            }
        }
    }
    
    public int add(int val) {
        int top = minHeap.peek();
        if(val>top) {
            minHeap.poll();
            minHeap.add(val);
        }
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */