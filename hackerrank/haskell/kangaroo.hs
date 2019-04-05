
-- Original Link 
-- https://www.hackerrank.com/challenges/kangaroo/problem

{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields, MultiWayIf #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

-------------- SOLUTION -----------------
-- Ideas 
-- 1) Assume kangaroo 1 is faster than kangaroo 2, if not just recall the function inverting teh arguments positions (so to avoid logic repetition)
-- 2) As kangaroo 1 is by design faster, if it also has a position advantage over kangaroo 2 they will never meet 
-- 3) If kangaroo 2 has a position advantage then it is possible they meet, just recursively recall the function by updating both the positions according to the speed 
-- 4) If both the kangaroos have the same speed, then the only possibility for them to meet is they also have the same position 
kangaroo :: Int -> Int -> Int -> Int -> String 
kangaroo x1 v1 x2 v2 
    | v1 > v2 = if 
        | x1 > x2 -> "NO"
        | x1 == x2 -> "YES"
        | x1 < x2 -> kangaroo (x1+v1) v1 (x2+v2) v2 
    | v2 > v1 = kangaroo x2 v2 x1 v1
    | v1 == v2 = if 
        | x1 == x2 -> "YES"
        | otherwise -> "NO"


-------------------------------------------


main :: IO()
main = do
    stdout <- getEnv "OUTPUT_PATH"
    fptr <- openFile stdout WriteMode

    x1V1X2V2Temp <- getLine
    let x1V1X2V2 = words x1V1X2V2Temp

    let x1 = read (x1V1X2V2 !! 0) :: Int

    let v1 = read (x1V1X2V2 !! 1) :: Int

    let x2 = read (x1V1X2V2 !! 2) :: Int

    let v2 = read (x1V1X2V2 !! 3) :: Int

    let result = kangaroo x1 v1 x2 v2

    hPutStrLn fptr result

    hFlush fptr
    hClose fptr



