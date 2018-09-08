#!/bin/ruby

## Solution to https://www.hackerrank.com/challenges/diagonal-difference/problem

require 'json'
require 'stringio'

# Complete the diagonalDifference function below.
def diagonalDifference(arr)
    # Debug 
    #p "Arr.length()=#{arr.length}" 
    d1 = 0 
    d2 = 0 
    for i in 0 .. arr.length-1
        d1 += arr[i][i]
        d2 += arr[i][arr.length-1-i]
    end
    return (d1-d2).abs
    
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = Array.new(n)

n.times do |i|
    arr[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = diagonalDifference arr

fptr.write result
fptr.write "\n"

fptr.close()


