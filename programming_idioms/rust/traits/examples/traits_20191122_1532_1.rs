struct Vector2
{
  x: f64, 
  y: f64 
}

struct Vector3
{
  x: f64, 
  y: f64, 
  z: f64 
}

trait Modulus 
{
  fn modulus(&self) -> f64; 
}

trait ToStr
{
  fn to_str(&self) -> String; 
}

impl Modulus for Vector2
{
  fn modulus(&self) -> f64 
  {
    return (self.x*self.x + self.y*self.y).sqrt(); 
  }
}

impl Modulus for Vector3 
{
  fn modulus(&self) -> f64 
  {
    return (self.x*self.x + self.y*self.y + self.z*self.z).sqrt(); 
  }
}

impl ToStr for Vector2
{
  fn to_str(&self) -> String
  {
    return format!("V2(x={:.2}, y={:.2})", self.x, self.y); 
  }
}

impl ToStr for Vector3
{
  fn to_str(&self) -> String
  {
    return format!("V3(x={:.2}, y={:.2}, z={:.2})", self.x, self.y, self.z); 
  }
}


fn main() {
  let a = Vector2{x: 10.0, y: 11.0}; 
  let b = Vector3{x: 31.0, y: 32.0, z: 33.0}; 
  println!("A={} \nB={}", a.to_str(), b.to_str()); 

  println!("A.modulus={} \nB.modulus={}", a.modulus(), b.modulus()); 
  println!("Hello World!");
}
