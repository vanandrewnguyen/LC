function findNumberOfLIS(nums: number[]): number {
    let n: number = nums.length;
    let len: number[] = new Array<number>(n).fill(1);
    let count: number[] = new Array<number>(n).fill(1);
    // len = length of longest subseq given index (see longest subseq q) 
    // count = count of LIS, we sum count for all indexes and possible increasing subseq (note single char = valid subseq)

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    // found longer subseq at i, reduce count to 0 to not double count
                    len[i] = len[j] + 1;
                    count[i] = 0;
                }
                if (len[j] + 1 == len[i]) {
                    // extend to create new longest increasing subsequence
                    count[i] += count[j];
                }
            }
        }
    }

    console.log(len, count);

    const maxLen: number = len.reduce((a, b) => Math.max(a, b), -Infinity);
    let res: number = 0;
    for (let i = 0; i < n; i++) {
        if (len[i] == maxLen) {
            res += count[i];
        }
    }

    return res;
};
