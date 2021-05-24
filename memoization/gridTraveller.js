const path=(m,n , memo={})=>{
    let key = m+','+n;
    if(key in memo){
        return memo[key];
    }
    if(m ===1 && n ===1){
        return 1;
    }
    if(m ===0 || n ===0){
        return 0;
    }
    memo[key] = path(m-1, n, memo) + path(m, n-1, memo);
    let key1 = n+','+m;
    memo[key1] = memo[key];
    return memo[key];
}

console.log(path(1,1));
console.log(path(18,18));
console.log(path(17,17));
console.log(path(16,16));
console.log(path(15,15));
