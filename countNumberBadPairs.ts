function countBadPairs(nums: number[]): number {
    // reorder the equation to give us:
    // j - i != nums(j) - nums(i)
    // nums(i) - i != nums(j) - j
    // store all good pairs and subtract from arithmetic sum n(n-1)/2
    
    let freq: Map<number, number> = new Map<number, number>();
    let goodPairs = 0;
    for (let i = 0; i < nums.length; i++) {
        const diff = i - nums[i];
        let count = freq.get(diff) || 0;
        goodPairs += count;
        freq.set(diff, count + 1);
    }

    const n = nums.length;
    return (n * (n - 1)) / 2 - goodPairs;
};
