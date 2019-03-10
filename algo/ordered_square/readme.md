
# Overview 

Input: Ordered List of Numbers, both positive and negative

Output: Ordered List of Square Values

Examples 

```
[-3, -1, 1, 2, 3] --> [1, 1, 4, 9, 9]
```

Caveat: 
- As Input Number can be both positive and negative, just squaring them breaks the initial ordering 


# Solutions 

## Naive 

1. Loop over the Input Array to compute square value of each number and put it into a temp array 
- Complexity: 
  - Time: `O(N)`
  - Space: `O(N)`

2. Sort the Array to recover order 
- Complexity 
  - Time: `O(N lnN)` on avg
  - Space: TBD (depends on specific algo)



## Efficient 

In order to make it better than naive, we need to aim for Linear Complexity which is actually possible because the initial array is ordered 

The challenge is then to compensate the order breaking effect of squaring at insert time so that no ex-post sorting is needed and the time complexity is just the min `O(N)` which is necessary to observe at least once each element 

1. Find the min abs value in the Input Array 
- It is `O(N)` worst case (when it is at the end) as we do not need to observe all the elements: as the input is guaranteed to be ordered, 
the min abs value is where the abs values sequences switching from being decreasing to increasing 

```pyhton
if(abs(v[i]) > abs(v[-1])): 
  # Min Abs Pos Found 
```


- As this is the min abs value element, squaring it provides the element with `id=0` in result list 

```python
k=0
res[k] = v[min_id]*v[min_id]
```

2. Move left and right from that position to 
- computing square values for each pair 
- compare them 
- add the smaller as next element in the result list 
- move forward the related index 
- repeat until both indexes reach the input array borders 


```python
i = min_id-1
j = min_id+1
k = 1
a = v[i]*v[i]
b = v[j]*v[j]
if(a<=b): 
  res[k] = a
  i -= 1
else: 
  res[k] = b 
  j += 1
```


- Complexity 
  - Time: `O(N)` including both the min research and the loop to square each element 
  - Space: `O(N)` for the result storage 



