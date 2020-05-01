// Solution to Hackerrank 2D Array 
// https://www.hackerrank.com/challenges/2d-array/problem

fn f_hourglass_count(a: &Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
  if (i+2 >= a.len()) || (j+2 >= a[0].len()) {return 0; }
  return a[i][j] + a[i][j+1] + a[i][j+2] + 
         a[i+1][j+1] +
         a[i+2][j] + a[i+2][j+1] + a[i+2][j+2]; 
}

fn get_max(a: &Vec<Vec<i32>>) -> (usize, usize, i32)
{
  let mut res = 0; 
  let mut best_i = 0; 
  let mut best_j = 0; 
  if a.len() == 0 {return (0,0,0);}
  for i in 0..a.len() {
    for j in 0..a[0].len() {
      let temp = f_hourglass_count(a,i,j); 
      if temp > res {best_i = i; best_j = j; res = temp;}
    }
  }
  return (best_i, best_j, res); 
}

fn main() {
  let a: Vec<Vec<i32>> = vec![ vec![1,2,3,1,2,3], vec![4,5,6,4,5,6], vec![7,8,9,7,8,9], vec![1,2,3,1,2,3], vec![4,5,6,4,5,6], vec![7,8,9,7,8,9] ]; 
  let res = get_max(&a); 
  println!("Max found at i={}, j={}, val={}", res.0, res.1, res.2); 
}

