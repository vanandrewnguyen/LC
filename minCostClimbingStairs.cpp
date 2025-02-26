function minCostClimbingStairs(cost: number[]): number {
    // mem array includes cost from prev accumulated jump
    // top down from n..0
    let n: number = cost.length;
    let mem: number[] = new Array(n+2).fill(0); // mem[i] = min cost

    mem[n] = 0;
    for (let i = n-1; i >= 0; i--) {
        mem[i] = cost[i] + Math.min(mem[i+1], mem[i+2]);
    }

    console.log(mem);
    return Math.min(mem[0], mem[1]);
};
