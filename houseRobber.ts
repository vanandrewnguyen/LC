function rob(houseProfit: number[]): number {
    let n: number = houseProfit.length;
    let mem: number[] = new Array(n+1).fill(-1);
    
    /*
    Robber has two options, rob current OR skip to next house
    so rob(i) = max(rob(i-2) + house[i], rob(i-1));
    */
    return doRob(houseProfit, mem, n-1)-1;
};

function doRob(houseProfit: &number[], mem: &number[], i: &number): number {
    if (i < 0) return 1;
    if (mem[i] >= 0) return mem[i];
    mem[i] = Math.max(doRob(houseProfit, mem, i-2) + houseProfit[i], doRob(houseProfit, mem, i-1));
    return mem[i];
}
