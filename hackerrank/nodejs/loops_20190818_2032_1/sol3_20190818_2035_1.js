'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}


/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s)
{
    var vowels = []; 
    var consonants = []; 

    // Loop1 : Discriminating between vowels and consonants 
    s.split('').forEach(function (x) { if (/[aeiou]/.test(x)) vowels.push(x); else consonants.push(x); }); 

    // Loop2 : Vowels print 
    vowels.forEach(function (x) { console.log(x); }); 

    // Loop3 : Consonants print 
    consonants.forEach(function (x) { console.log(x); }); 
}


function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}
