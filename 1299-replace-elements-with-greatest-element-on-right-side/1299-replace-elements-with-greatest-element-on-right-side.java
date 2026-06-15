class Solution {
    public int[] replaceElements(int[] arr) {
        int greatest = -1;
        int n = arr.length;
        for(int i=n-1; i>=0; i--) {
            int temp = arr[i];
            arr[i] = greatest;
            greatest = Math.max(greatest, temp);
        }

        return arr;
    }
}