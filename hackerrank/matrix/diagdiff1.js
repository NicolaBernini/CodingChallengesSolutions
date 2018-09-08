
// Solution to https://www.hackerrank.com/challenges/diagonal-difference/problem

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/**
  * @brief The O(N) solution JS implementation is very similar to the C++ one 
  * @note The arr is an Array of Arrays which is the typical Core Language (with no external libs) representation for a Matrix and an element can be accessed with double square bracket syntax 
  * @note The Array Size is like in C++ represented as a Container property, just a syntactic difference as C++ provides it via the size() member while JS provides it via the length property 
  */
function diagonalDifference(arr) 
{
    let d1=0; 
    let d2=0; 
    for(let i=0; i<arr.length; ++i)
    {
        d1 += arr[i][i]; 
        d2 += arr[i][arr.length-1-i];
    }
    return Math.abs(d1-d2); 
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    let arr = Array(n);

    for (let i = 0; i < n; i++) {
        arr[i] = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));
    }

    const result = diagonalDifference(arr);

    ws.write(result + '\n');

    ws.end();
}



