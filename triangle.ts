function minimumTotal(triangle: number[][]): number {
    // go down triangle tree such that we edit inplace to include sum of smallest
    // path, then on the last line, take the smallest entry
    let n: number = triangle.length;
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < triangle[i].length; j++) {
            // get from prev level
            if (j == 0) {
                triangle[i][j] += triangle[i-1][0];
            } else if (j == triangle[i].length-1) {
                triangle[i][j] += triangle[i-1][triangle[i-1].length-1];
            } else {
                // min
                triangle[i][j] += Math.min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }

    console.log(triangle);

    // get min of last elem
    return Math.min.apply(Math, triangle[triangle.length-1]);
};
