function mergeArrays(nums1: number[][], nums2: number[][]): number[][] {
    let m = new Map<number, number>();
    let res: number[][] = [];

    for (let i = 0; i < nums1.length; i++) {
        m.set(nums1[i][0], nums1[i][1]);
    }
    for (let i = 0; i < nums2.length; i++) {
        if (m.has(nums2[i][0])) {
            m.set(nums2[i][0], m.get(nums2[i][0]) + nums2[i][1]);
        } else {
            m.set(nums2[i][0], nums2[i][1]);
        }
    }

    m.forEach((value, key) => {
        res.push([key, value]);
    });
    res.sort((a, b) => a[0] - b[0]);

    return res;
}
