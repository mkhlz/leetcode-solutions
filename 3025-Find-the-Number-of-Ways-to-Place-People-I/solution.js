var numberOfPairs = function(points) {
    points.sort((a, b) => (a[0] === b[0]) ? b[1] - a[1] : a[0] - b[0]);
    let n = points.length, ans = 0;
    for (let i = 0; i < n; i++) {
        let yi = points[i][1];
        let maxY = -Infinity;
        for (let j = i + 1; j < n; j++) {
            let yj = points[j][1];
            if (yj <= yi && yj > maxY) {
                ans++;
                maxY = yj;
            }
        }
    }
    return ans;
};