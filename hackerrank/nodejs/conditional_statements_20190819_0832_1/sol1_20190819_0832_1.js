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

function getGrade(score) {
    let grade;
    // Write your code here
    for (var i = 0; i < 6; ++i)
    { 
        if ((score > 5 * i) && (score <= 5 * (i + 1))) grade = String.fromCharCode("F".charCodeAt(0) - i); 
    }

    return grade;
}
