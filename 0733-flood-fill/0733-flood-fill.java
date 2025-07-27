class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int targetColor;
        if(sr>=0 && sr<image.length && sc>=0 && sc<image[0].length)
            targetColor = image[sr][sc];
        else
            return image;

        System.out.println(targetColor);
        
        fill(image, sr, sc, color, targetColor);
        return image;
    }

    private void fill(int[][] image, int sr, int sc, int color, int targetColor) {
        if(sr<0 || sr>=image.length || sc<0 || sc>=image[0].length || image[sr][sc]!=targetColor)
            return;

        if(image[sr][sc]==color)
            return;

        image[sr][sc] = color;
        
        fill(image, sr+1, sc, color, targetColor);
        fill(image, sr-1, sc, color, targetColor);
        fill(image, sr, sc+1, color, targetColor);
        fill(image, sr, sc-1, color, targetColor);

        return;
    }
}