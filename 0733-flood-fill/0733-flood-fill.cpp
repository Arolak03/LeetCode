class Solution {
public:
    
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();
        
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor) {
            return;
        }
        
        // Change the color of the current pixel
        image[sr][sc] = color;
        
        // Recursively call in four directions
        solve(image, sr + 1, sc, color, originalColor);
        solve(image, sr - 1, sc, color, originalColor);
        solve(image, sr, sc + 1, color, originalColor);
        solve(image, sr, sc - 1, color, originalColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        if (originalColor != color) { // Avoid unnecessary recursion
            solve(image, sr, sc, color, originalColor);
        }
        
        return image;
    }
};
