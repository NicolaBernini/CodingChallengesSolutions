
-- Original Link 
-- https://www.hackerearth.com/practice/algorithms/searching/linear-search/tutorial/

get_last :: [Int] -> Int -> Int -> Maybe Int -> Int 

get_last [] _ _ Nothing = -1 
get_last [] _ _ (Just c) = (c+1)
get_last arr q c r 
  | (arr!!0)==q = get_last (drop 1 arr) q (c+1) (Just c)
  | otherwise = get_last (drop 1 arr) q (c+1) r 


main = do 
    first <- getLine :: IO String
    second <- getLine :: IO String
    let a = words first 
    let q = (read (a!!1)) :: Int 
    let b = words second
    let c = (map read b) :: [Int] 
    putStrLn $ show $ get_last c q 0 Nothing 
