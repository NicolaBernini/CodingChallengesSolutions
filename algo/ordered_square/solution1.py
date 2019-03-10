
g_v = [-3, -1, 1, 2, 3]

def square(v): 
  res = [None]*len(v)
  if(len(v)==1): 
    res[0] = v[0]*v[0]
    return res

  for i in range(len(v)): 
    if(i>0): 
      if(abs(v[i]) > abs(v[i-1]) ) or (i == len(v)-1): 
        # FOUND MIN
        min_id = i-1
        break 
  print("MinID=", min_id, " --> Val=", v[min_id])
  i=min_id
  j=min_id+1
  k=0 

  while True: 
    print("Working on k=", k, ", i=", i, ", j=", j)
    print("Partial res=", res)
    if(i<0): 
      a = None
    else: 
      a = v[i]*v[i]
    
    if(j==len(v)): 
      b = None 
    else: 
      b = v[j]*v[j]
    
    if( a==None and b==None ): 
      break 

    if(a!=None): 
      if(b!=None): 
        if(a<=b): 
          res[k] = a
          i -= 1 
        else: 
          res[k] = b
          j += 1
      else: 
        res[k] = a
        i -= 1
    else: 
      if(b!=None): 
        res[k] = b
        j += 1 
    k += 1



square(g_v)
