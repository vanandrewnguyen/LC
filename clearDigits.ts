function clearDigits(s: string): string {
    let n: number = s.length;
    let res: string = "";
    let stack: string[] = [];
    for (let i = 0; i < n; i++) {
        stack.push(s[i]);
        if (!isNaN(Number(s[i]))) {
            stack.pop();
            stack.pop();
        }
    }

    for (let i = 0; i < stack.length; i++) {
        res += stack[i];
    }

    return res;
};
