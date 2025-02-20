function tupleSameProduct(nums: number[]): number {
    let res: number = 0;
    let freq: Map<number, number> = new Map<number, number>();

    // get all products and make map where key = prod, val = number of pairs
    for (let i = 0; i < nums.length; i++) {
        for (let j = i+1; j < nums.length; j++) {
            const prod = nums[i] * nums[j];
            freq.set(prod, (freq.get(prod) || 0) + 1);
        }
    }

    console.log(freq.size);

    // Number of total pairs (a,b,c,d) = 2 * pairs * 2 * (pairs-1)
    freq.forEach((value, key) => { 
        res += 4 * value * (value - 1);
    });


    return res;
};
