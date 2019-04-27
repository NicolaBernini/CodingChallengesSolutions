-- Original Link 
-- https://projecteuler.net/problem=1
filter_multiples :: [Int] -> [Int] -> [Int] -> [Int]

filter_multiples _ [] partial = partial 

filter_multiples divisors list partial 
    | cond = filter_multiples divisors (drop 1 list) (partial ++ [q]) 
    | otherwise = filter_multiples divisors (drop 1 list) partial
    where 
        q = list!!0 
        cond = or [ q `mod` x == 0 | x <- divisors ]


main = do 
  let a = filter_multiples [3,5] [0..1000] [] 
  putStrLn $ show $ sum a 





