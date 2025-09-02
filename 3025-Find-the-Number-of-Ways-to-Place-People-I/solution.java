import java.util.*;

class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int n = points.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int yi = points[i][1];
            int maxY = Integer.MIN_VALUE;
            for (int j = i + 1; j < n; j++) {
                int yj = points[j][1];
                if (yj <= yi && yj > maxY) {
                    ans++;
                    maxY = yj;
                }
            }
        }
        return ans;
    }
};