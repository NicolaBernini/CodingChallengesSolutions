

fn main() {
  let mut a = [[0 as u8; 4]; 4]; 
  a[1][1] = 1; 
  for (i, row) in a.iter().enumerate() 
  {
    for (j, _col) in row.iter().enumerate() 
    {
      println!("(row={}, col={}) = {}", i, j, a[i][j]); 
    }
  }

  println!("Hello World!");
}




