-- Sample code to perform I/O:

is_even :: Int -> Bool 
is_even n = n `mod` 2 == 0

is_prime :: Int -> Bool 
is_prime n 
  | n == 0 = False 
  | n == 1 = False 
  | n == 2 = True 
  | n == 3 = True 
  | is_even n = False
  | otherwise = not (or [ ((n `mod` x)==0) | x <- [3,5 .. (n-1)] ]) 

next_prime :: Int -> Int 
next_prime n 
  | n == 1 = 2
  | (is_even n) && (is_prime (n+1) == True)  = n+1
  | (not (is_even n)) && (is_prime (n+2) == True) = n+2
  | (is_even n) && (is_prime (n+1) == False) = next_prime (n+1)
  | (not (is_even n)) && (is_prime (n+2) == False) = next_prime (n+2)


primes_list :: Int -> Int -> [Int] -> [Int]
primes_list n c arr 
  | c > n = arr 
  | c <= n = primes_list n (next_prime c) (arr++[c])


-- Just for Output Format 
conv :: [Int] -> String -> String 
conv arr s 
  | s == "" = conv (drop 1 $ arr) (show (arr!!0))
  | arr == [] = s 
  | otherwise = conv (drop 1 $ arr) (s ++ " " ++ (show (arr!!0)))


main = do
    n <- readLn :: IO Int 
    putStrLn (conv (primes_list n 2 []) "")

