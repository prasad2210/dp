const allConstruct= (str, bank)=>{
    const table = Array(str.length +1).fill().map(()=>[]);
    table[0] = [[]];

    for(let i =0; i<=str.length; i++){
        for(let word of bank){
            if(str.slice(i, i+word.length) === word){
                const combinations = table[i].map(subarray => [...subarray, word]);
                table[i + word.length].push(...combinations);
            }
        }
    }
    return table[str.length];
};

console.log(allConstruct('purple', ['purp', 'p', 'ur', 'le', 'purpl']));

console.log(allConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd', 'ef', 'c']));


