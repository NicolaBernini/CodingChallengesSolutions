// Solution to 
// https://www.hackerrank.com/challenges/simple-array-sum/problem

// Example Input 
// 6
// 1 2 3 4 10 11

// Example Output 
// 31 

// Explanation 
// 1+2+3+4+10+11 = 31 

use std::io::Read;
use std::io::stdin;

fn main() {
	let mut s = String::new();
	stdin().read_to_string(&mut s);

	let vals = s.lines().nth(1).unwrap().split(" "); 
	let mut res: i32 = 0; 
	for v in vals
	{
		res += v.trim().parse::<i32>().unwrap(); 
	}
	
	println!("{}",res); 
}





